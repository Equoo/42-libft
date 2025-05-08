/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:58:40 by dderny            #+#    #+#             */
/*   Updated: 2025/05/08 16:39:05 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

t_vec_header	*_vec_header(t_vec vector)
{
	return ((t_vec_header *)vector - 1);
}

t_vec_header	*_vec_realloc(t_vec_header *vector, size_t new_capacity)
{
	t_vec_header	*new_vector;

	if (new_capacity == 0)
	{
		free(vector);
		return (NULL);
	}
	new_vector = ft_realloc(vector, sizeof(t_vec_header)
		+ new_capacity * vector->type_size);
	
	return (new_vector);
}
