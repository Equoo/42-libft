/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:40:00 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 18:46:57 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "p_printf.h"
#include <stddef.h>
#include <stdlib.h>

size_t	string_to_str(char *buffer, const size_t size, char *str,
		t_format_tag tag)
{
	size_t	str_len;
	size_t	written;

	written = 0;
	if (!str)
	{
		str_len = ft_min(6, size);
		ft_memcpy(buffer, "(void)", str_len);
		return (str_len);
	}
	str_len = ft_strlen(str);
	ft_memcpy(buffer, str, str_len);
	written = str_len;
	if (tag.flags & FLAG_FREE)
		free(str);
	return (written);
}
