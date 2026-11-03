/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:13:58 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/03 12:16:17 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_dprintf.h"

static void	printer(const char *format, va_list args, int i, int fd)
{
	if (format[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), fd);
	else if (format[i + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), fd);
	else if (format[i + 1] == 'p')
		ft_putptr_fd(va_arg(args, void *), fd);
	else if (format[i + 1] == 'd')
		ft_putnbr_fd(va_arg(args, int), fd);
	else if (format[i + 1] == 'i')
		ft_putnbr_fd(va_arg(args, int), fd);
	else if (format[i + 1] == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), fd);
	else if (format[i + 1] == 'x')
		ft_puthexa_fd(va_arg(args, unsigned int), fd, "0123456789abcdef");
	else if (format[i + 1] == 'X')
		ft_puthexa_fd(va_arg(args, unsigned int), fd, "0123456789ABCDEF");
	else
		ft_putchar_fd('%', fd);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	va_list	args_count;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	va_copy(args_count, args);
	i = 0;
	count = ft_countargs(format, &args_count);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printer(format, args, i, fd);
			i++;
		}
		else
			ft_putchar_fd(format[i], fd);
		i++;
	}
	va_end(args_count);
	va_end(args);
	return (count);
}
