/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:49:59 by dderny            #+#    #+#             */
/*   Updated: 2025/03/15 18:53:24 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdint.h>
#include <stdlib.h>

ssize_t	vec_extend(t_vector *vec, ssize_t x)
{
	uint8_t	*data;

	vec->size = vec->size << x;
	data = malloc(vec->size * vec->type_size);
	free(vec->data);
	if (!data)
		return (0);
	vec->data = data;
	return (vec->size);
}
