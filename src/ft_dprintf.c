/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:48:00 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 20:47:42 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

/* Loops through the format string and prints the corresponding argument */
static int	loop(char c, va_list *args, int fd)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(*args, int), fd);
	if (c == 's')
		count += ft_putstr_fd(va_arg(*args, char *), fd);
	if (c == 'p')
		count += ft_putptr_fd(va_arg(*args, void *), fd);
	if (c == 'd' || c == 'i')
		count += ft_putnbr_fd(va_arg(*args, int), fd);
	if (c == 'u')
		count += ft_putunbr_fd(va_arg(*args, unsigned int), fd);
	if (c == 'x')
		count += ft_puthexa_fd(va_arg(*args, unsigned int), fd, HEX_LOW);
	if (c == 'X')
		count += ft_puthexa_fd(va_arg(*args, unsigned int), fd, HEX_UP);
	if (c == '%')
		count += ft_putchar_fd('%', fd);
	else
		count += ft_putchar_fd('%', 1) + ft_putchar_fd(c, 1);
	return (count);
}

/* Prints the formatted string and returns the number of characters printed */
int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += loop(format[i], &args, fd);
		}
		else
			count += ft_putchar_fd(format[i], fd);
		i++;
	}
	va_end(args);
	return (count);
}
