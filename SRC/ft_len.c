/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamatter <mamatter@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:11:46 by mamatter          #+#    #+#             */
/*   Updated: 2026/11/03 12:16:17 by mamatter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_dprintf.h"

int	ft_unbrlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_ullnbrlen(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_nbrlen(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		i += 6;
		return (i);
	}
	while (s[i])
		i++;
	return (i);
}

int	ft_ptrlen(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += ft_strlen("(nil)");
	else
		count += ft_ullnbrlen((unsigned long long)ptr) + 2;
	return (count);
}
