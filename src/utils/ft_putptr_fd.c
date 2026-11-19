/* =====================================================
 * File        : ft_putptr_fd.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Writes an pointer to a file descriptor. 
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../../ft_dprintf.h"

/* Writes an pointer to a file descriptor. */
int	ft_putptr_fd(void *p, int fd)
{
	int	count;

	if (fd < 0)
		return (0);
	if (!p)
	{
		count = ft_putstr_fd("(nil)", fd);
		return (count);
	}
	count = ft_putstr_fd("0x", fd);
	count += ft_puthexa_fd((unsigned long)p, fd, HEX_LOW);
	return (count);
}
