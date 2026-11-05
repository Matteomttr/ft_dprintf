/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 12:24:45 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/05 10:18:08 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

/* Writes a string to a file descriptor. */
int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (0);
	if (!s)
	{
		i = write(fd, "(null)", 6);
		return (i);
	}
	i = write(fd, s, ft_strlen(s));
	return (i);
}
