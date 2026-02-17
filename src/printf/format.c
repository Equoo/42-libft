/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:08:38 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 04:02:45 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>

static size_t	cp_to_next_tag(char *buffer, char **format, const size_t size)
{
	size_t	i;

	i = 0;
	while ((i + 1) < size && **format)
	{
		if (**format == '%')
		{
			(*format)++;
			if (**format == '%')
			{
				buffer[i] = **format;
				i++;
				(*format)++;
				continue ;
			}
			return (i);
		}
		buffer[i] = **format;
		i++;
		(*format)++;
	}
	return (i);
}

int	vformat(char *str, const size_t size, char *format, va_list ap)
{
	size_t			written;
	t_format_tag	tag;
	t_fvalue		value;

	written = 0;
	while (*format)
	{
		written += cp_to_next_tag(str + written, &format, size - written);
		if (!*format)
			break ;
		tag = tag_from_str(&format);
		if (tag.precision == -2)
			tag.precision = va_arg(ap, int);
		value = get_value(ap, tag);
		written += value_to_str(str + written, size - written, value, tag);
	}
	str[written] = 0;
	return (written);
}

int	format(char *str, const size_t size, char *format, ...)
{
	va_list	ap;
	int		count;

	if (!str || !format)
		return (-1);
	va_start(ap, format);
	count = vformat(str, size, format, ap);
	va_end(ap);
	return (count);
}
