/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:55:50 by dderny            #+#    #+#             */
/*   Updated: 2025/05/05 05:15:05 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

t_vector	vec_new(ssize_t start_size, uint8_t type_size)
{
	t_vector	vec;

	if (start_size < 4)
		start_size = 4;
	vec.size = start_size;
	vec.start_size = start_size;
	vec.type_size = type_size;
	vec.actual_size = 0;
	vec.data = ft_calloc(start_size, type_size);
	if (!vec.data)
		vec.data = NULL;
	return (vec);
}
