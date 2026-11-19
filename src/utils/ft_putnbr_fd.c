/* =====================================================
 * File        : ft_putnbr_fd.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Writes an integer to a file descriptor.
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */


#include "../../ft_dprintf.h"

/* Writes an integer to a file descriptor. */
int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		count;

	if (fd < 0)
		return (0);
	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	count += ft_putunbr_fd(nb, fd);
	return (count);
}
