/* =====================================================
 * File        : ft_strlen.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Returns the length of a string. 
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../../ft_dprintf.h"

/* Returns the length of a string. */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
