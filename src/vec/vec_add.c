/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:24:12 by dderny            #+#    #+#             */
/*   Updated: 2025/05/03 01:01:28 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"
#include <stdlib.h>

t_vector	vec_add(const t_vector veca, const t_vector vecb)
{
	t_vector	new;

	if (veca.type_size == vecb.type_size)
		return ((t_vector){0});
	new = vec_new(veca.actual_size + vecb.actual_size, veca.type_size);
	new.start_size = veca.start_size + vecb.start_size;
	new.actual_size = veca.actual_size + vecb.actual_size;
	new.size = new.actual_size;
	free(veca.data);
	free(vecb.data);
	if (!new.data)
		return (new);
	ft_memcpy(new.data, veca.data, veca.actual_size * veca.type_size);
	ft_memcpy(new.data + veca.actual_size * veca.type_size,
		vecb.data, vecb.actual_size * vecb.type_size);
	return (new);
}
