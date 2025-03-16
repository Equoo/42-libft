/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:24:12 by dderny            #+#    #+#             */
/*   Updated: 2025/03/16 23:17:00 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	vec_add(const t_vector veca, const t_vector vecb)
{
	t_vector	new;

	if (veca.type_size == vecb.type_size)
		return ((t_vector){0});
	new = vec_new(veca.actual_size + vecb.actual_size, veca.type_size);
	new.start_size = veca.start_size + vecb.start_size;
	new.actual_size = veca.actual_size + vecb.actual_size;
	new.size = new.actual_size;
	return (new);
}
