/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:00:07 by dderny            #+#    #+#             */
/*   Updated: 2024/11/15 18:13:26 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

extern size_t	ft_strlen(const char *str)
{
	const char	*const_str;

	const_str = str;
	while (*const_str != '\0')
		++const_str;
	return (const_str - str);
}
