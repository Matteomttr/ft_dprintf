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
