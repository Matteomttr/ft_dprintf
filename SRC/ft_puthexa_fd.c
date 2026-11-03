#include "../ft_dprintf.h"

void	ft_puthexa_fd(unsigned long long n, int fd, char *base)
{
	if (fd < 0)
		return ;
	if (n >= 16)
		ft_puthexa_fd(n / 16, fd, base);
	ft_putchar_fd(base[n % 16], fd);
}
