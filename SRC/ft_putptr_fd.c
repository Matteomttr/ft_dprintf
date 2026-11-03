#include "../ft_dprintf.h"

void	ft_putptr_fd(void *ptr, int fd)
{
	if (fd < 0)
		return ;
	if (ptr == NULL)
		write(fd, "(nil)", 5);
	else
	{
		write(fd, "0x", 2);
		ft_puthexa_fd((unsigned long long)(ptr), 1, "0123456789abcdef");
	}
}
