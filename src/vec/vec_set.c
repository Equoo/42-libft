/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:15:11 by dderny            #+#    #+#             */
/*   Updated: 2025/03/15 18:53:40 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"
#include <stdint.h>

int	vec_set(t_vector *vec, ssize_t index, void *val)
{
	if (index >= vec->size)
		return (1);
	ft_memcpy(vec->data + index * vec->type_size, val, vec->type_size);
	return (0);
}
