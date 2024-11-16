/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:48:23 by dderny            #+#    #+#             */
/*   Updated: 2024/11/13 15:12:57 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

extern void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*array;

	i = 0;
	array = NULL;
	if ((unsigned long long)nmemb * (unsigned long long)size > SIZE_MAX)
		return (NULL);
	array = malloc(nmemb * size);
	if (array)
	{
		while (i < nmemb * size)
			((char *)array)[i++] = 0;
	}
	return (array);
}
