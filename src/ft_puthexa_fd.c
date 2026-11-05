/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:29:42 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/05 10:17:41 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

/* Writes a hexadecimal to a file descriptor. */
int	ft_puthexa_fd(unsigned long n, int fd, char *base)
{
	int	count;

	if (fd < 0)
		return (0);
	count = 0;
	if (n >= 16)
		count += ft_puthexa_fd(n / 16, fd, base);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}
