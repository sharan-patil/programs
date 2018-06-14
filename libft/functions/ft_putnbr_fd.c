/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:19:30 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:19:32 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	char	givealpha(int n)
{
	return (n + 48);
}

static	int		check(int n, char *sign, int fd)
{
	if (n < 0)
	{
		sign[0] = '-';
		write(fd, &sign[0], 1);
		n *= -1;
	}
	return (n);
}

static	int		check2(int n, long int *temp, long int *p, long int *i)
{
	temp[0] = n;
	while (temp[0] != 0)
	{
		p[0] *= 10;
		temp[0] /= 10;
		i[0]++;
	}
	p[0] /= 10;
	return (0);
}

void			ft_putnbr_fd(int n, int fd)
{
	long int	i[1];
	long int	temp[1];
	long int	p[1];
	char		sign[1];

	i[0] = 0;
	p[0] = 1;
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
	n = check(n, sign, fd);
	check2(n, temp, p, i);
	while (p[0] != 0)
	{
		ft_putchar_fd(givealpha(n / p[0]), fd);
		n %= p[0];
		p[0] /= 10;
	}
}
