/* =====================================================
 * File        : ft_dprintf.h
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Header for ft_dprintf
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */


#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

/* Inclusion of necessary libraries */
# include <stdarg.h>
# include <unistd.h>

/* Constants */
# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

/* Main function */
int 	ft_dprintf(int fd, const char *format, ...) __attribute__ ((format (printf, 2, 3)));

/* Utility functions */
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_puthexa_fd(unsigned long n, int fd, char *base);
int		ft_putptr_fd(void *p, int fd);
size_t	ft_strlen(const char *s);

#endif
