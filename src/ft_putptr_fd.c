/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:21:59 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/05 10:18:18 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

/* Writes an pointer to a file descriptor. */
int	ft_putptr_fd(void *p, int fd)
{
	int	count;

	if (fd < 0)
		return (0);
	if (!p)
	{
		count = ft_putstr_fd("(nil)", fd);
		return (count);
	}
	count = ft_putstr_fd("0x", fd);
	count += ft_puthexa_fd((unsigned long)p, fd, HEX_LOW);
	return (count);
}
