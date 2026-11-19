/* =====================================================
 * File        : ft_dprintf.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : Main file
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */


#include "../ft_dprintf.h"

/* Loops through the format string and prints the corresponding argument */
static int	ft_loop(char c, va_list *args, int fd)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(*args, int), fd);
	else if (c == 's')
		count += ft_putstr_fd(va_arg(*args, char *), fd);
	else if (c == 'p')
		count += ft_putptr_fd(va_arg(*args, void *), fd);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_fd(va_arg(*args, int), fd);
	else if (c == 'u')
		count += ft_putunbr_fd(va_arg(*args, unsigned int), fd);
	else if (c == 'x')
		count += ft_puthexa_fd(va_arg(*args, unsigned int), fd, HEX_LOW);
	else if (c == 'X')
		count += ft_puthexa_fd(va_arg(*args, unsigned int), fd, HEX_UP);
	else if (c == '%')
		count += ft_putchar_fd('%', fd);
	else
		count += ft_putchar_fd('%', fd) + ft_putchar_fd(c, fd);
	return (count);
}

/* Prints the formatted string and returns the number of characters printed */
int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format && fd < 0)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += ft_loop(format[i], &args, fd);
		}
		else
			count += ft_putchar_fd(format[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}
