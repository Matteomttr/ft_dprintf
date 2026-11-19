/* =====================================================
 * File        : ft_putchar_fd
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Writes a character to a file descriptor.
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */


#include "../../ft_dprintf.h"

/* Writes a character to a file descriptor. */
int	ft_putchar_fd(char c, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (i);
	i = write(fd, &c, 1);
	return (i);
}
