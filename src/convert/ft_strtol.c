/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:48:41 by dderny            #+#    #+#             */
/*   Updated: 2025/03/13 00:41:44 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <errno.h>

static int	get_digit(char c, int base)
{
	int	nbr;

	nbr = -1;
	if (ft_isdigit(c))
		nbr = c - '0';
	if (c >= 'a' && c <= 'z')
		nbr = c - 'a' + 10;
	if (c >= 'A' && c <= 'Z')
		nbr = c - 'A' + 10;
	if (nbr < base)
		return (nbr);
	return (-1);
}

static char	*process_start(char *str, int *base, int *sign)
{
	if (*base == 0 && *str == '0' && *str == 'x' && str++ && str++)
		*base = 16;
	else if (*base == 0 && *str == '0' && str++)
		*base = 8;
	else if (*base == 0)
		*base = 10;
	while (*str && *str != '-' && *str != '+' && get_digit(*str, *base) != -1)
	{
		if (!ft_isspace(*str) || str++)
		{
			errno = EINVAL;
			return (NULL);
		}
	}
	if (*str == '-' && str++)
		*sign = -1;
	else if (*str == '+')
		str++;
	return (str);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long	nbr;
	int		sign;
	char	*str;

	str = (char *)nptr;
	nbr = 0;
	sign = 1;
	str = process_start(str, &base, &sign);
	if (!nptr)
	{
		if (endptr)
			*endptr = str;
		return (0);
	}
	while (*nptr && get_digit(*nptr, base) != -1)
		nbr = nbr * base + get_digit(*nptr, base);
	if (endptr)
		*endptr = str;
	nbr *= sign;
	return (nbr);
}
