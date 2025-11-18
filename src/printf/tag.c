/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:03:26 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:06:55 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_printf.h"
#include "libft.h"
#include <limits.h>

static t_format_sizes	tag_get_size(char **c)
{
	if (**c == 'l' && (*c)++)
	{
		if (**c == 'l' && (*c)++)
			return (FSIZE_LL);
		else
			return (FSIZE_L);
	}
	else if (**c == 'h' && (*c)++)
	{
		if (**c == 'h' && (*c)++)
			return (FSIZE_HH);
		else
			return (FSIZE_H);
	}
	else if (**c == 'z' && (*c)++)
		return (FSIZE_Z);
	else if (**c == 'w' && (*c)++)
		return (FSIZE_W);
	return (0);
}

static int	get_digit(char **c)
{
	int	nbr;

	nbr = -1;
	if (ft_isdigit(**c))
	{
		nbr = **c - '0';
		(*c)++;
	}
	return (nbr);
}

int	tag_get_number(char **str)
{
	int		nbr;
	int		digit;

	nbr = 0;
	if (!ft_isdigit(**str) || **str == '0')
		return (-1);
	digit = get_digit(str);
	while (digit != -1)
	{
		if (nbr > (INT_MAX - digit) / 10)
		{
			nbr = INT_MAX;
			break ;
		}
		else
			nbr = nbr * 10 + digit;
		digit = get_digit(str);
	}
	return (nbr);
}

t_format_tag	tag_from_str(char **format)
{
	t_format_tag	tag;

	tag = (t_format_tag){.precision = -1};
	while (get_flag(**format, &tag.flags))
		(*format)++;
	tag.width = tag_get_number(format);
	if (**format == '.' && (*format)++)
	{
		if (**format == '*')
			tag.precision = -2;
		else
			tag.precision = tag_get_number(format);
	}
	tag.size = tag_get_size(format);
	if (get_typeflag(**format, &tag.flags))
		(*format)++;
	else
		(void)tag; // TODO: ERROR
	return (tag);
}
