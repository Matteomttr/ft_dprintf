/* =====================================================
 * File        : ft_puthexa_fd.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Writes a hexadecimal to a file descriptor. 
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */


#include "../../ft_dprintf.h"

/* Writes a hexadecimal to a file descriptor. */
int	ft_puthexa_fd(unsigned long n, int fd, char *base)
{
	int	count;

	if (fd < 0)
		return (0);
	count = 0;
	if (n >= 16)
		count += ft_puthexa_fd(n / 16, fd, base);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}
