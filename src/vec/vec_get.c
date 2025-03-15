/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:15:11 by dderny            #+#    #+#             */
/*   Updated: 2025/03/15 18:53:26 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stddef.h>
#include <stdint.h>

void	*vec_get(t_vector *vec, ssize_t index)
{
	if (index >= vec->size)
		return (NULL);
	return (vec->data + vec->type_size * index);
}
