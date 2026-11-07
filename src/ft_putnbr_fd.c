/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 12:24:22 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/07 18:04:39 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

/* Writes an integer to a file descriptor. */
int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		count;

	if (fd < 0)
		return (0);
	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	count += ft_putunbr_fd(nb, fd);
	return (count);
}
