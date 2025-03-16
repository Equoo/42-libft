/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:55:50 by dderny            #+#    #+#             */
/*   Updated: 2025/03/16 23:15:18 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

t_vector	vec_new(ssize_t start_size, uint8_t type_size)
{
	t_vector	vec;

	vec.size = start_size;
	vec.start_size = start_size;
	vec.type_size = type_size;
	vec.actual_size = 0;
	vec.data = ft_calloc(start_size, type_size);
	if (!vec.data)
		vec.data = NULL;
	return (vec);
}
