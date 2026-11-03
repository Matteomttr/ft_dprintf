/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:11:46 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/03 12:16:17 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_dprintf.h"

static int	counter(const char *format, va_list *args, int i)
{
	int	count;

	count = 0;
	if (format[i + 1] == 'c')
	{
		count++;
		(void)va_arg(*args, int);
	}
	else if (format[i + 1] == 's')
		count += ft_strlen(va_arg(*args, char *));
	else if (format[i + 1] == 'p')
		count += ft_ptrlen(va_arg(*args, void *));
	else if (format[i + 1] == 'd')
		count += ft_nbrlen(va_arg(*args, int));
	else if (format[i + 1] == 'i')
		count += ft_nbrlen(va_arg(*args, int));
	else if (format[i + 1] == 'u')
		count += ft_unbrlen(va_arg(*args, unsigned int));
	else if (format[i + 1] == 'x')
		count += ft_ullnbrlen(va_arg(*args, unsigned int));
	else if (format[i + 1] == 'X')
		count += ft_ullnbrlen(va_arg(*args, unsigned int));
	else
		count++;
	return (count);
}

int	ft_countargs(const char *format, va_list *args)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += counter(format, args, i);
			i++;
		}
		else
			count++;
		i++;
	}
	return (count);
}
