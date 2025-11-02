/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:01:12 by dderny            #+#    #+#             */
/*   Updated: 2025/05/12 13:03:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t__xgarbage	*_alloc_garbage(void *ptr)
{
	return (((t__alloc *)ptr - 1)->garbage);
}

t__alloc	*_alloc_header(void *ptr)
{
	return ((t__alloc *)ptr - 1);
}

int	_garbage_init(t__xgarbage *garbage)
{
	*garbage = (t__xgarbage){NULL, -1, 4, 0, 0};
	garbage->allocations = malloc(sizeof(t__alloc) * garbage->capacity);
	if (!garbage->allocations)
		return (1);
	return (0);
}
