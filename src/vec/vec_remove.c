/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:24:12 by dderny            #+#    #+#             */
/*   Updated: 2025/05/03 06:24:53 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"
#include <stddef.h>

int	vec_remove(t_vector *vec, ssize_t index)
{
	if (index >= vec->actual_size)
		return (0);
	ft_memmove(vec->data + index * vec->type_size,
		vec->data + (index + 1) * vec->type_size,
		(vec->actual_size - index - 1) * vec->type_size);
	ft_bzero(vec->data + (vec->actual_size - 1) * vec->type_size,
		vec->type_size);
	vec->actual_size--;
	return (1);
}
