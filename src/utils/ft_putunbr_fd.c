/* =====================================================
 * File        : ft_putunbr_fd.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Writes an unsigned integer to a file descriptor. 
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../../ft_dprintf.h"

/* Writes an unsigned integer to a file descriptor. */
int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	if (fd < 0)
		return (0);
	count = 0;
	if (n > 9)
		count += ft_putunbr_fd(n / 10, fd);
	count += ft_putchar_fd(n % 10 + '0', fd);
	return (count);
}
