/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:03:15 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:07:58 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_printf.h"

t_format_flags	get_typeflag(char c, t_format_flags *out)
{
	const char		flags[] = FORMAT_TYPES;
	t_format_flags	res;
	size_t			i;

	i = 2;
	if (c == flags[0] || c == flags[1])
	{
		*out |= FLAG_I;
		return (FLAG_I);
	}
	while (i < sizeof(FORMAT_TYPES))
	{
		if (c == flags[i])
		{
			res = 1 << (i - 1);
			*out |= res;
			return (res);
		}
		i++;
	}
	return (0);
}

t_format_flags	get_flag(char c, t_format_flags *out)
{
	const char		flags[] = FORMAT_FLAGS;
	t_format_flags	res;
	size_t			i;

	i = 0;
	while (i < sizeof(FORMAT_FLAGS))
	{
		if (c == flags[i])
		{
			res = 1 << (i + TYPES_N);
			*out |= res;
			return (res);
		}
		i++;
	}
	return (0);
}
