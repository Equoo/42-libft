/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:03:10 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:03:12 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_printf.h"
#include "libft.h"

static int	get_base_fromtag(char **base, t_format_tag tag)
{
	int	len;

	len = 10;
	*base = BASE10;
	if (tag.flags & FLAG_I || tag.flags & FLAG_U)
		len = 10;
	else if (tag.flags & FLAG_O)
		len = 8;
	else
	{
		*base = BASE16L;
		len = 16;
		if (tag.flags & FLAG_XU)
			*base = BASE16U;
	}
	return (len);
}

static int	has_flags(t_format_flags a, t_format_flags b)
{
	return ((a & b) == b);
}

static size_t	unsigned_headers(char *str, t_format_flags flags)
{
	size_t	written;
	char	*header;

	written = 0;
	header = 0;
	if (has_flags(flags, FLAG_HASH | FLAG_O))
		header = "0";
	else if (has_flags(flags, FLAG_HASH | FLAG_X) || flags & FLAG_P)
		header = "0x";
	else if (has_flags(flags, FLAG_HASH | FLAG_XU))
		header = "0X";
	if (header)
	{
		written = ft_strlen(header);
		if (str)
			ft_memcpy(str, header, written);
	}
	return (written);
}

size_t	unsigned_to_str(char *str, const size_t size,
					uint64_t nb, t_format_tag tag)
{
	char		*base;
	const int	baselen = get_base_fromtag(&base, tag);
	size_t		nb_len;
	size_t		total;
	size_t		len;

	nb_len = get_nb_len(nb, baselen, &tag, 0);
	nb_len += unsigned_headers(NULL, tag.flags);
	total = ft_lmax(tag.width, nb_len);
	if ((size_t)(total + 1) >= size)
		return (0);
	len = nb_len - 1;
	nb_fill_char(str, tag, total);
	if (!(tag.flags & FLAG_MINUS))
		str += ft_lmax(tag.width - nb_len, 0);
	unsigned_headers(str, tag.flags);
	if (!nb)
		str[0] = '0';
	while (nb)
	{
		str[len--] = base[nb % baselen];
		nb /= baselen;
	}
	return (total);
}
