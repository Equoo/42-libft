/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:02:07 by dderny            #+#    #+#             */
/*   Updated: 2025/11/01 05:19:06 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_xalloc(t__xgarbage *garbage, size_t size, id_t mapid)
{
	t__alloc	*tmp;
	void		*ptr;

	if (!garbage->allocations)
		return (NULL);
	if (garbage->allocations && garbage->size >= garbage->capacity)
	{
		garbage->capacity *= 2;
		tmp = malloc(sizeof(t__alloc) * garbage->capacity);
		if (!tmp)
			return (NULL);
		ft_memcpy(tmp, garbage->allocations, sizeof(t__alloc) * garbage->size);
		free(garbage->allocations);
		garbage->allocations = tmp;
	}
	ptr = malloc(size + sizeof(size_t));
	if (!ptr)
		return (NULL);
	*(size_t *)ptr = garbage->size;
	garbage->allocations[garbage->size] = (t__alloc){size, mapid, garbage, ptr};
	garbage->size++;
	return (ptr + sizeof(size_t));
}

void	*ft_alloc(t__xgarbage *garbage, size_t size)
{
	return (ft_xalloc(garbage, size, 0));
}
