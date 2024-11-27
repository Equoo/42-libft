/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dderny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:00:07 by dderny            #+#    #+#             */
/*   Updated: 2024/11/27 16:42:37 by dderny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	s_int;
	size_t	*int_str;
	int		i;

	if (!*str)
		return (0);
	int_str = (size_t *)str;
	while (*int_str)
	{
		s_int = *int_str++;
		if ((s_int - 0x1010101010101010) & ~s_int & 0x8080808080808080)
		{
			i = 0;
			while (i < (int)sizeof(s_int) && ((const char *)(int_str - 1))[i])
				i++;
			if (i != sizeof(s_int))
				return (s_int = (const char *)(int_str - 1) - (const char *)str + i);
		}
	}
	return ((const char *)int_str - str);
}

/* #include <pthread.h>
#include "libft.h"
#include <dlfcn.h>
#include <errno.h>
#include <execinfo.h>
#include <fcntl.h>
#include <limits.h>
#include <locale.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <time.h>
#include <unistd.h>

void	*electric_alloc(size_t size)
{
	long	page_size;
	void	*ptr;

	page_size = sysconf(_SC_PAGESIZE);
	ptr = mmap(NULL, page_size * 2, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	memset(ptr, 'Z', page_size * 2);
	mprotect(ptr + page_size, page_size, PROT_NONE);
	return (ptr + page_size - size);
}

int	main(void)
{
	char	*str;

	str = electric_alloc(37);
	ft_strlcpy(str, "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz", 34);
	__builtin_printf("%s   ;   %lu; %lu\n", str, ft_strlen(str), strlen(str));
}
 */