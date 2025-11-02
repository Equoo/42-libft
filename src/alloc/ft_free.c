/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:03:34 by dderny            #+#    #+#             */
/*   Updated: 2025/05/26 04:19:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	*ft_free(void *ptr)
{
	t__alloc	*alloc;
	t__xgarbage	*data;
	size_t		id;

	if (!ptr)
		return (NULL);
	alloc = _alloc_header(ptr);
	data = alloc->garbage;
	if (!data->allocations)
	{
		free(ptr);
		return (NULL);
	}
	id = alloc->id;
	if (id < data->size && data->allocations[id] == alloc)
	{
		free(alloc);
		data->allocations[id] = NULL;
		data->last_freed = id;
		return (NULL);
	}
	ft_dprintf(STDERR_FILENO,
		"Error: trying to free a pointer that was not allocated by ft_alloc\n");
	free(ptr);
	return (NULL);
}

void	*ft_xfree(t__xgarbage *data, id_t mapid)
{
	size_t		i;

	i = 0;
	while (i < data->size)
	{
		if (data->allocations[i] && (mapid == 0
				|| data->allocations[i]->mapid & mapid))
			ft_free(data->allocations[i]);
		i++;
	}
	return (NULL);
}

//__attribute__((destructor)) 
void	*garbage_collector(t__xgarbage *data)
{
	size_t		total;
	size_t		i;

	if (!data->allocations)
		return (NULL);
	i = 0;
	total = 0;
	while (i < data->size)
	{
		if (!data->allocations[i] && ++i)
			continue ;
		total += data->allocations[i]->size;
		ft_free(data->allocations[i]);
		i++;
	}
	free(data->allocations);
	if (total && DEBUG)
		ft_dprintf(STDERR_FILENO,
			"Warning: total memory garbage collected: %u bytes\n",
			total);
	return (NULL);
}
