/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:55:50 by dderny            #+#    #+#             */
/*   Updated: 2025/04/30 01:44:40 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdlib.h>

int	vec_destroy(t_vector *vec)
{
	if (vec->data)
		free(vec->data);
	*vec = (t_vector){0};
	return (1);
}
