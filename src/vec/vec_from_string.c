/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_from_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:36:59 by dderny            #+#    #+#             */
/*   Updated: 2025/05/03 02:36:11 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"
#include <stdint.h>

t_vector	vec_from_string(char *str)
{
	t_vector	vec;
	size_t		len;

	vec = (t_vector){};
	vec.data = (uint8_t *)ft_strdup(str);
	len = ft_strlen(str);
	vec.actual_size = len;
	vec.start_size = len;
	vec.size = len;
	vec.type_size = 1;
	return (vec);
}
