/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 12:24:53 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/04 20:02:57 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_dprintf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return (i);
	i = write(fd, &c, 1);
	return (i);
}
