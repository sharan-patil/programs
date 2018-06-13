#include <libft.h>

static	char	givealpha(int n)
{
	return (n + 48);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int i, temp, len, p;
	char sign;
	i = 0;
	p = 1;
	if (n == 0)
	{
		ft_putstr_fd("0", fd);
		return ;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		sign = '-';
		write(fd, &sign, 1);
		n *= -1;
	}
	temp = n;
	while (temp != 0)
	{
		p *= 10;
		temp /= 10;
		i++;
	}
	p /= 10;
	len = i;
	while (p != 0)
	{
		ft_putchar_fd(givealpha(n / p), fd);
		n %= p;
		p /= 10;
	}
}
