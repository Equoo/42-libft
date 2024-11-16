/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:09:52 by dderny            #+#    #+#             */
/*   Updated: 2024/11/13 17:36:30 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

extern char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;

	len = ft_strlen(s) + 1;
	cpy = ft_calloc(len, sizeof(char));
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s, len);
	return (cpy);
}
