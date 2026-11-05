/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 12:24:53 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/05 10:17:26 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

/* Writes a character to a file descriptor. */
int	ft_putchar_fd(char c, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (i);
	i = write(fd, &c, 1);
	return (i);
}
