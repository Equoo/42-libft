/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoato.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:39:23 by dderny            #+#    #+#             */
/*   Updated: 2025/04/01 21:04:02 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_itoato(int n, char *dst)
{
	int		rlen;
	int		len;
	long	nb;

	if (!dst)
		return (0);
	len = 0;
	if (n < 0 || !n)
		len++;
	nb = n;
	while (nb && ++len)
		nb /= 10;
	rlen = len;
	nb = (long)n;
	if (nb < 0)
	{
		dst[0] = '-';
		nb *= -1;
	}
	while ((n && nb && len--) || (!n && len--))
	{
		dst[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (rlen);
}
