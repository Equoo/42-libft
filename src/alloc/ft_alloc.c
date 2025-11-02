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
#include <sys/types.h>
#include <unistd.h>

static void	*alloc(t__xgarbage *garbage, t__alloc *ptr, size_t size, id_t mapid)
{
	ptr = malloc(sizeof(t__alloc) + size);
	if (!ptr)
		return (NULL);
	*ptr = (t__alloc){0};
	ptr->size = size;
	ptr->mapid = mapid;
	ptr->garbage = garbage;
	if (garbage->last_freed == (size_t)-1)
	{
		garbage->allocations[garbage->size] = ptr;
		ptr->id = garbage->size;
		garbage->size++;
	}
	else
	{
		garbage->allocations[garbage->last_freed] = ptr;
		ptr->id = garbage->last_freed;
		garbage->last_freed = -1;
	}
	return (ptr + 1);
}

void	*ft_xalloc(t__xgarbage *garbage, size_t size, id_t mapid)
{
	t__alloc	*ptr;

	ptr = NULL;
	if (!garbage->allocations)
		return (NULL);
	if (garbage->last_freed == (size_t)-1
		&& garbage->allocations
		&& garbage->size >= garbage->capacity)
	{
		garbage->capacity *= 2;
		ptr = malloc(sizeof(t__alloc *) * garbage->capacity);
		if (!ptr)
			return (NULL);
		ft_memcpy(ptr, garbage->allocations,
			sizeof(t__alloc *) * garbage->size);
		free(garbage->allocations);
		garbage->allocations = (t__alloc **)ptr;
	}
	return (alloc(garbage, ptr, size, mapid));
}

void	*ft_alloc(t__xgarbage *garbage, size_t size)
{
	return (ft_xalloc(garbage, size, 0));
}
