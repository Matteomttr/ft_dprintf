/* =====================================================
 * File        : ft_putstr_fd.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Writes a string to a file descriptor.
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../../ft_dprintf.h"

/* Writes a string to a file descriptor. */
int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (0);
	if (!s)
	{
		i = write(fd, "(null)", 6);
		return (i);
	}
	i = write(fd, s, ft_strlen(s));
	return (i);
}
