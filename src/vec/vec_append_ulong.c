/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_append_ulong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:29:56 by dderny            #+#    #+#             */
/*   Updated: 2025/05/03 04:14:33 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <stdint.h>
#include <sys/types.h>

int	vec_append_ulong(t_vector *vec, u_long val)
{
	return (vec_append(vec, &val));
}
