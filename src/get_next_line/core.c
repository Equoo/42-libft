/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:25:54 by dderny            #+#    #+#             */
/*   Updated: 2026/02/18 22:08:57 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

static t_gnl_data	*getfddata(int fd)
{
	static t_gnl_data	data[OPEN_MAX];
	int					i;

	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < OPEN_MAX && data[i].fd != fd)
		i++;
	if (i == OPEN_MAX)
	{
		i = 0;
		while (data[i].state != GNL_UNUSED)
			i++;
		if (i == OPEN_MAX)
			return (NULL);
		data[i] = (t_gnl_data){.fd = fd, .state = GNL_INUSE};
	}
	return (&data[i]);
}

static char	*read_line(t_gnl_data *data, char *last, int *len)
{
	char	*buffer;

	buffer = NULL;
	*len = -1;
	while (data->pos == -1 && *len)
	{
		*len = read(data->fd, data->buf, BUFFER_SIZE);
		if (!*len)
			data->state = GNL_ENDED;
		if (*len == -1 || (!*len && !buffer && !last[0]))
			return (free(last), NULL);
		data->buf[*len] = 0;
		data->pos = get_newline(data->buf);
		if (data->pos != -1)
			*len = data->pos;
		buffer = gnl_strdup(data->buf, *len + 1);
		buffer = gnl_strjoin(last, buffer);
		if (!buffer)
			return (NULL);
		last = buffer;
	}
	if (last && !buffer && !*len)
		return (last);
	return (buffer);
}

static char	*read_buffer(t_gnl_data *data, int *len)
{
	ssize_t	newline;
	char	*line;

	line = data->buf + data->pos + 1;
	newline = get_newline(line);
	if (newline == -1)
	{
		line = gnl_strdup(line, 0);
		if (!line)
			return (NULL);
		data->pos = -1;
		return (read_line(data, line, len));
	}
	line = gnl_strdup(line, newline + 1);
	if (!line)
		line = NULL;
	data->pos += newline + 1;
	return (line);
}

int	get_next_line(int fd, char **line)
{
	t_gnl_data	*data;
	int			len;

	data = getfddata(fd);
	if (!data)
		return (-1);
	errno = 0;
	*line = NULL;
	if (data->state != GNL_ENDED)
	{
		if (data->pos != -1 && !data->buf[data->pos + 1])
		{
			data->pos = -1;
			*line = gnl_strdup("", 0);
			if (*line)
				*line = read_line(data, *line, &len);
		}
		else
			*line = read_buffer(data, &len);
	}
	if (!line)
		*data = (t_gnl_data){.state = GNL_UNUSED, .pos = 0, .fd = 0};
	if (errno)
		return (-1);
	return (len);
}
