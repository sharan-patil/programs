/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 15:04:30 by spatil            #+#    #+#             */
/*   Updated: 2017/07/16 15:04:33 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		solveexp(int a, char b, int c);

int		solvenobrac(char *ray, int *nums);

int		ft_atoi(char *str);

void	ft_putnbr(int a);

void	ft_putchar(char a);

int		solvebrac(char *syms, int *nums)
{
	int x;

	x = 0;
	int z = 0;
	printf("syms: %s\n", syms);
	while (z < 3)
	{
		printf("nums[%d]: %d\n", z, nums[z]);
		z++;
	}
	while (syms[x] != '\0')
	{
		if (syms[x] == '(')
			if (syms[x + 2] == ')')
				{
					nums[x + 1] = solveexp(nums[x], syms[x + 1], nums[x + 1]);
					syms[x + 1] = ' ';
				}
			x++;
	}
	z = 0;
	printf("x: %d\n", x);
	printf("syms: %s\n", syms);
	while (z < 3)
	{
		printf("nums[%d]: %d\n", z, nums[z]);
		z++;
	}
	return (solvenobrac(syms, nums));
}

int		solveexp(int a, char b, int c)
{
	if (b == '+')
		return (a + c);
	else if (b == '-')
		return (a - c);
	else if (b == '*')
		return (a * c);
	else if (b == '/')
		return (a / c);
	else
		return (a % c);
}

int		checkbracs(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '(' || str[x] == ')')
			return (1);
		x++;
	}
	return (0);
}

void	ft_putnbr(int a)
{
	int b;
	int x;
	int y;
	int num[10];

	x = 1;
	b = 1;
	y = 0;
	while (a / (b *= 10) != 0)
		x++;
	while ((b /= 10) > 0)
	{
		num[y] = a / b;
		a = a - (a / b) * b;
		y++;
	}
	b = 0;
	while (b < x)
	{
		num[b] = num[b] + 48;
		write(1, &num[b], 1);
		b++;
	}
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}