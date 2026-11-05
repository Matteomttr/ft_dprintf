/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:50:48 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/05 10:18:31 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

/* Writes an unsigned integer to a file descriptor. */
int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	if (fd < 0)
		return (0);
	count = 0;
	if (n > 9)
		count += ft_putunbr_fd(n / 10, fd);
	count += ft_putchar_fd(n % 10 + '0', fd);
	return (count);
}
