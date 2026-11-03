/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:11:46 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/03 12:16:17 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_dprintf.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return ;
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}
