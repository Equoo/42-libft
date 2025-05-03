/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_insert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:24:12 by dderny            #+#    #+#             */
/*   Updated: 2025/05/03 10:11:51 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"
#include <stddef.h>

int	vec_insert_int(t_vector *vec, int val, ssize_t index)
{
	if (index > vec->actual_size)
		return (1);
	if (vec->actual_size >= vec->size && !vec_extend(vec, 1))
		return (1);
	if (vec->actual_size > 0 && index < vec->actual_size)
	{
		ft_memmove(vec->data + (index + 1) * vec->type_size,
			vec->data + index * vec->type_size,
			(vec->actual_size - index) * vec->type_size);
	}
	vec->actual_size++;
	return (vec_set(vec, index, &val));
}
