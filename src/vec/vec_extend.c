/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:49:59 by dderny            #+#    #+#             */
/*   Updated: 2025/04/17 22:04:46 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

ssize_t	vec_extend(t_vector *vec, ssize_t x)
{
	uint8_t	*data;

	vec->size = vec->size << x;
	data = malloc(vec->size * vec->type_size);
	if (!data)
	{
		free(vec->data);
		return (0);
	}
	ft_memcpy(data, vec->data, vec->actual_size * vec->type_size);
	ft_bzero(data + vec->actual_size * vec->type_size,
		(vec->size - vec->actual_size) * vec->type_size);
	free(vec->data);
	vec->data = data;
	return (vec->size);
}
