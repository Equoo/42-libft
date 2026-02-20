/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:09:47 by dderny            #+#    #+#             */
/*   Updated: 2026/02/20 18:45:24 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_PRINTF_H
# define P_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

# define PRINTF_BUFFER_SIZE 4096
# define FORMAT_FLAGS "-+0 #!"
# define TYPES_N 10
# define FORMAT_TYPES "diuoxXfFcsp"

# define BASE10 "0123456789"
# define BASE16L "0123456789abcdef"
# define BASE16U "0123456789ABCDEF"

typedef enum e_format_sizes
{
	FSIZE_NONE,
	FSIZE_HH,
	FSIZE_H,
	FSIZE_LL,
	FSIZE_L,
	FSIZE_Z,
	FSIZE_W,
}							t_format_sizes;

typedef enum e_format_flags
{
	FLAG_I = 1,
	FLAG_U = 1 << 1,
	FLAG_O = 1 << 2,
	FLAG_X = 1 << 3,
	FLAG_XU = 1 << 4,
	FLAG_F = 1 << 5,
	FLAG_FU = 1 << 6,
	FLAG_C = 1 << 7,
	FLAG_S = 1 << 8,
	FLAG_P = 1 << 9,
	FLAG_MINUS = 1 << 10,
	FLAG_PLUS = 1 << 11,
	FLAG_ZERO = 1 << 12,
	FLAG_SPACE = 1 << 13,
	FLAG_HASH = 1 << 14,
	FLAG_FREE = 1 << 15
}							t_format_flags;

typedef struct s_format_tag
{
	t_format_flags			flags;
	int						width;
	int						precision;
	t_format_sizes			size;
}							t_format_tag;

typedef union s_fvalue
{
	int64_t					int64;
	uint64_t				uint64;
	intptr_t				ptr;
	char					*s;
	float					f;
	char					c;
	unsigned char			uc;
	short int				si;
	int						i;
	long int				li;
	long long int			lli;
	unsigned short int		su;
	unsigned int			u;
	unsigned long int		lu;
	unsigned long long int	llu;
	size_t					size;
}							t_fvalue;

void						nb_fill_char(char *str, t_format_tag tag,
								const size_t total);
size_t						get_nb_len(const int64_t snb, const int base,
								t_format_tag *tag, const int issigned);

size_t						value_to_str(char *buffer, size_t size,
								t_fvalue value, t_format_tag tag);
t_fvalue					get_value(va_list ap, t_format_tag tag);

t_format_tag				tag_from_str(char **format);
t_format_flags				get_flag(char c, t_format_flags *out);
t_format_flags				get_typeflag(char c, t_format_flags *out);

size_t						signed_to_str(char *str, const size_t size,
								int64_t nb, t_format_tag tag);
size_t						unsigned_to_str(char *str, const size_t size,
								uint64_t nb, t_format_tag tag);
size_t						double_to_str(char *str, size_t size, float nb,
								t_format_tag tag);
size_t						string_to_str(char *buffer, const size_t size,
								char *str, t_format_tag tag);

#endif
