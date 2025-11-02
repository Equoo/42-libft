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

t__xgarbage	*_alloc_garbage(void *ptr)
{
	return (((t__alloc *)ptr - 1)->garbage);
}

t__alloc	*_alloc_header(void *ptr)
{
	return ((t__alloc *)ptr - 1);
}
