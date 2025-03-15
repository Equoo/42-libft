/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_append.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:29:56 by dderny            #+#    #+#             */
/*   Updated: 2025/03/15 18:53:12 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int	vec_append(t_vector *vec, void *val)
{
	if (vec->actual_size >= vec->size && vec_extend(vec, 1))
		return (0);
	return (vec_set(vec, vec->actual_size, val));
}
