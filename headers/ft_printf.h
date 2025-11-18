/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:10 by dderny            #+#    #+#             */
/*   Updated: 2025/11/18 02:28:28 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

/**
** @brief Prints a formatted string to the standard output using a variable
** argument list.
**
** This function is similar to printf, but it takes a va_list
** argument instead of a variable number of arguments.
**
** @param format The format string that specifies how subsequent
** arguments are converted for output.
** @param ap A va_list that contains the variable arguments to be
** formatted and printed.
**
** @return The number of characters printed (excluding the null byte
** used to end output to strings).
*/
int				ft_vprintf(const char *format, va_list ap);

/**
** @brief Prints a formatted string to the standard output using a variable
** argument list.
**
** This function is similar to printf, but it takes a va_list
** argument instead of a variable number of arguments.
**
** @param fd The fd to print to.
** @param format The format string that specifies how subsequent
** arguments are converted for output.
** @param ap A va_list that contains the variable arguments to be
** formatted and printed.
**
** @return The number of characters printed (excluding the null byte
** used to end output to strings).
*/
int				ft_vdprintf(int fd, const char *format, va_list ap);

/**
** @brief Produces output according to a format.
**
** This function sends formatted output to stdout, using the format string
** specified. The format string can contain format specifiers that are
** replaced by the values of the additional arguments, formatted as requested.
**
** @param format A null-terminated string containing the format specifiers.
**               The format specifiers follow the same specifications as the
**               standard printf function.
** @param ...    Additional arguments specifying the data to be printed
**               according to the format specifiers.
**
** @return The number of characters printed (excluding the null byte used to
**         end output to strings), or a negative value if an output error occurs.
*/
int				ft_printf(const char *format, ...);

/**
** @brief Produces output according to a format.
**
** This function sends formatted output to stdout, using the format string
** specified. The format string can contain format specifiers that are
** replaced by the values of the additional arguments, formatted as requested.
**
** @param fd The fd to print to.
** @param format A null-terminated string containing the format specifiers.
**               The format specifiers follow the same specifications as the
**               standard printf function.
** @param ...    Additional arguments specifying the data to be printed
**               according to the format specifiers.
**
** @return The number of characters printed (excluding the null byte used to
**         end output to strings), or a negative value if an output error occurs.
*/
int				ft_dprintf(int fd, const char *format, ...);

int	format(char *str, const size_t size, char *format, ...);
int	vformat(char *str, const size_t size, char *format, va_list ap);

#endif
