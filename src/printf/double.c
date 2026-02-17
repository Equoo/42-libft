/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 04:05:12 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 04:48:09 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "p_printf.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

// static int	has_flags(t_format_flags a, t_format_flags b)
// {
// 	return ((a & b) == b);
// }

size_t	err_to_str(char *str, size_t size, float nb)
{
	size_t	sup;

	sup = 0;
	if (isinff(nb))
	{
		if (size >= 1 && nb < 0 && size-- && ++sup)
			str[0] = '-';
		if (size >= 4)
			ft_memcpy(str + sup, "inff", 4);
		return (4 + sup);
	}
	if (isnan(nb))
	{
		if (size >= 3)
			ft_memcpy(str, "nan", 3);
		return (3);
	}
	return (0);
}

size_t	double_to_str(char *str, size_t size, float nb, t_format_tag tag)
{
	int64_t		base;
	uint64_t	fract;
	size_t		total;
	size_t		total2;

	total = err_to_str(str, size, nb);
	if (total)
		return (total);
	base = (int64_t)nb;
	fract = (uint64_t)((nb - base + 1) * 1000000);
	total = signed_to_str(str, size, base, (t_format_tag){.size = FSIZE_L});
	total2 = unsigned_to_str(str + total, ft_max(size - total, 0), fract,
			(t_format_tag){.flags = FLAG_I, .size = FSIZE_L});
	str[total] = '.';
	total += total2;
	(void)tag;
	return (total);
}
