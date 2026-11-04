/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 12:24:45 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 20:05:55 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

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
