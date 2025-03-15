/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:37 by dderny            #+#    #+#             */
/*   Updated: 2025/03/15 18:53:03 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdint.h>
# include <stdio.h>

typedef struct s_vector
{
	uint8_t	*data;
	uint8_t	type_size;
	ssize_t	start_size;
	ssize_t	actual_size;
	ssize_t	size;
}			t_vector;

t_vector	vec_new(ssize_t start_size, uint8_t type_size);
void		vec_destroy(t_vector *vec);
ssize_t		vec_extend(t_vector *vec, ssize_t x);
t_vector	vec_add(const t_vector veca, const t_vector vecb);

int			vec_set(t_vector *vec, ssize_t index, void *val);
void		*vec_get(t_vector *vec, ssize_t index);
int			vec_append(t_vector *vec, void *val);

#endif