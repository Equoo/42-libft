/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <dderny@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:47:32 by dderny            #+#    #+#             */
/*   Updated: 2026/02/17 03:59:35 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "p_printf.h"
#include <unistd.h>

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	buffer[PRINTF_BUFFER_SIZE];
	int		len;

	len = vformat(buffer, PRINTF_BUFFER_SIZE, (char *)format, ap);
	if (write(fd, buffer, len) == -1)
		return (-1);
	return (len);
}

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(STDOUT_FILENO, format, ap));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	if (fd < 0 || !format)
		return (-1);
	va_start(ap, format);
	count = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (count);
}
