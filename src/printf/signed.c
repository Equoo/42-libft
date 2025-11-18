/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:03:24 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:04:07 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_printf.h"
#include "libft.h"
#include <stdint.h>

void	nb_fill_char(char *str, t_format_tag tag, const size_t total)
{
	if (tag.width != -1)
		ft_memset(str, ' ', tag.width);
	if (tag.precision == -1)
		return ;
	ft_memset(str + ft_max(total - tag.precision, 0), '0', tag.precision);
}

size_t	get_nb_len(const int64_t snb, const int base,
						t_format_tag *tag, const int issigned)
{
	size_t		len;
	uint64_t	nb;

	len = 0;
	nb = snb;
	if (issigned && snb < 1)
		nb = ~nb + 1;
	while (nb)
	{
		nb /= base;
		len++;
	}
	if (!len)
		len = 1;
	if (tag->precision == -1 && tag->flags & FLAG_ZERO)
	{
		tag->precision = tag->width;
		tag->width = -1;
	}
	len = ft_max(len, tag->precision);
	if (issigned
		&& (snb < 0 || tag->flags & (FLAG_PLUS | FLAG_SPACE)))
		len++;
	return (len);
}

static void	add_sign(char *str, int64_t nb, t_format_flags flags)
{
	if (nb < 0)
		str[0] = '-';
	else if (flags & FLAG_PLUS)
		str[0] = '+';
	else if (flags & FLAG_SPACE)
		str[0] = ' ';
}

size_t	signed_to_str(char *str, const size_t size,
					int64_t nb, t_format_tag tag)
{
	const size_t	nb_len = get_nb_len(nb, 10, &tag, 1);
	const size_t	total = ft_lmax(tag.width, nb_len);
	size_t			len;

	if ((size_t)(total + 1) >= size)
		return (0);
	len = nb_len - 1;
	nb_fill_char(str, tag, total);
	if (!(tag.flags & FLAG_MINUS))
		str += ft_lmax(tag.width - nb_len, 0);
	add_sign(str, nb, tag.flags);
	if (nb < 0)
		nb *= -1;
	if (!nb)
		str[0] = '0';
	while (nb)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (total);
}
