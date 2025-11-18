/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:03:29 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:05:04 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_printf.h"
#include "libft.h"

static t_fvalue	get_signed_value(va_list ap, t_format_tag tag)
{
	t_fvalue	v;

	v.int64 = 0;
	if (tag.size == FSIZE_HH || tag.flags & FLAG_C)
		v.int64 = (char)va_arg(ap, int);
	else if (tag.size == 0)
		v.int64 = va_arg(ap, int);
	else if (tag.size == FSIZE_H)
		v.int64 = (short int)va_arg(ap, int);
	else if (tag.size == FSIZE_L)
		v.int64 = va_arg(ap, long int);
	else if (tag.size == FSIZE_LL)
		v.int64 = va_arg(ap, long long int);
	return (v);
}

static t_fvalue	get_unsigned_value(va_list ap, t_format_tag tag)
{
	t_fvalue	v;

	v.int64 = 0;
	if (tag.size == FSIZE_HH)
		v.uc = va_arg(ap, unsigned int);
	else if (tag.size == 0)
		v.u = va_arg(ap, unsigned int);
	else if (tag.size == FSIZE_H)
		v.su = va_arg(ap, unsigned int);
	else if (tag.size == FSIZE_L)
		v.lu = va_arg(ap, unsigned long int);
	else if (tag.size == FSIZE_LL)
		v.llu = va_arg(ap, unsigned long long int);
	return (v);
}

t_fvalue	get_value(va_list ap, t_format_tag tag)
{
	t_fvalue	v;

	v.int64 = 0;
	if (tag.flags & (FLAG_P | FLAG_S))
		v.ptr = va_arg(ap, intptr_t);
	else if (tag.flags & (FLAG_F | FLAG_FU))
		v.f = va_arg(ap, double);
	else if (tag.flags & (FLAG_I | FLAG_C))
		v = get_signed_value(ap, tag);
	else
		v = get_unsigned_value(ap, tag);
	return (v);
}

size_t	value_to_str(char *buffer, size_t size,
				t_fvalue value, t_format_tag tag)
{
	size_t	written;

	written = 0;
	if (tag.flags & FLAG_I)
		written = signed_to_str(buffer, size, value.int64, tag);
	else if (tag.flags & (FLAG_P | FLAG_X | FLAG_XU | FLAG_O | FLAG_U))
		written = unsigned_to_str(buffer, size, value.uint64, tag);
	else if (tag.flags & FLAG_C)
	{
		*buffer = value.c;
		written = 1;
	}
	else if (tag.flags & FLAG_S)
	{
		ft_memcpy(buffer, value.s, ft_strlen(value.s)); // TODO: MIN SIZE
		written = ft_strlen(value.s);
	}
	// else if (tag.flags & (FLAG_F | FLAG_FU))
		// written = double_to_str(buffer, size, value.double, tag);
	return (written);
}
