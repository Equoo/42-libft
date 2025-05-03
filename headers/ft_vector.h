/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:37 by dderny            #+#    #+#             */
/*   Updated: 2025/05/03 09:20:07 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdint.h>
# include <stdio.h>
# include <sys/types.h>

typedef struct s_vector
{
	uint8_t	*data;
	uint8_t	type_size;
	ssize_t	start_size;
	ssize_t	actual_size;
	ssize_t	size;
}			t_vector;

t_vector	vec_new(ssize_t start_size, uint8_t type_size);
int			vec_destroy(t_vector *vec);
ssize_t		vec_extend(t_vector *vec, ssize_t x);
t_vector	vec_add(const t_vector veca, const t_vector vecb);
t_vector	vec_from_string(char *str);
int			vec_append_ulong(t_vector *vec, u_long val);
t_vector	vec_insert(const t_vector veca, const t_vector vecb, size_t index);
int			vec_remove(t_vector *vec, ssize_t index);
int			vec_append_int(t_vector *vec, int val);
int			vec_insert_int(t_vector *vec, int val, ssize_t index);

int			vec_set(t_vector *vec, ssize_t index, void *val);
void		*vec_get(t_vector *vec, ssize_t index);
int			vec_append(t_vector *vec, void *val);

#endif
