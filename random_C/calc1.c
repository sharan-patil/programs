/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:36:08 by spatil            #+#    #+#             */
/*   Updated: 2017/07/15 14:36:08 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		doit(int *ar, int l);
char	*checksym(char *str);
int		*checknum(char *str);
int		solvenobrac(char *ray, int *nums);
int		sna(char *ray, int *nums, int y);
int		solvebrac(char *syms, int *nums);
int		solveexp(int a, char b, int c);
int		checkbracs(char *str);
int		snahelp(char *ray);
void	ft_putnbr(int a);
void	ft_putchar(char a);

int		eval_expr(char *str)
{
	char	*symbols;
	int		*nums;
	int		x;
	int		y;

	symbols = checksym(str);
	nums = checknum(str);
	x = 0;
	if (checkbracs(str) == 0)
		return (solvenobrac(symbols, nums));
	else
		return (solvebrac(symbols, nums));
}

int		solvenobrac(char *ray, int *nums)
{
	int x;

	x = -1;
	while (ray[++x] != '\0')
	{
		if (ray[x] == '/')
		{
			nums[x + 1] = nums[x] / nums[x + 1];
			ray[x] = ' ';
			nums[x] = -1;
		}
		if (ray[x] == '*')
		{
			nums[x + 1] = nums[x] * nums[x + 1];
			ray[x] = ' ';
			nums[x] = -1;
		}
		if (ray[x] == '%')
		{
			nums[x + 1] = nums[x] % nums[x + 1];
			ray[x] = ' ';
			nums[x] = -1;
		}
	}
	return (sna(ray, nums, x));
}

int		sna(char *ray, int *nums, int y)
{
	int x;
	int z;

	x = -1;
	z = -1;
	while ((z = snahelp(ray)) == -1)
	{
		if (ray[x] == '+' || ray[x] == '-')
		{
			y = x + 1;
			while (nums[y] == -1)
				y++;
			nums[y] = ray[x] == '+' ? nums[x] + nums[y] : nums[y];
			nums[y] = ray[x] == '-' ? nums[x] - nums[y] : nums[y];
			ray[x] = ' ';
		}
		x++;
	}
	return (nums[y]);
}

int		snahelp(char *ray)
{
	int z;

	z = 0;
	while (ray[z] != '\0')
	{
		if (ray[z] != ' ')
		{
			z = -1;
			break ;
		}
		else
			z++;
	}
	return (z);
}

char	*checksym(char *str)
{
	char	*syms;
	int		x;
	int		y;

	y = 0;
	x = 0;
	syms = malloc(sizeof(char) * 20);
	while (str[x] != '\0')
	{
		if (str[x] == '(' || str[x] == ')' || str[x] == '+' || str[x] == '-'
			|| str[x] == '*' || str[x] == '/' || str[x] == '%')
		{
			syms[y] = str[x];
			y++;
		}
		x++;
	}
	return (syms);
}

int		*checknum(char *str)
{
	int *numray;
	int tempnum[10];
	int x;
	int y;
	int z;

	x = -1;
	y = 0;
	z = -1;
	numray = malloc(sizeof(int) * 20);
	while (str[++x] != '\0')
	{
		while (str[x] >= '0' && str[x] <= '9')
		{
			tempnum[y] = str[x] - 48;
			y++;
			x++;
		}
		if (y != 0)
			numray[++z] = doit(tempnum, y);
		y = 0;
	}
	z = 0;
	while (z < 2)
	{
		printf("%d\n", numray[z]);
		z++;
	}
	return (numray);
}

int		doit(int *ar, int l)
{
	int x;
	int p;
	int ans;
	int power;

	power = 1;
	ans = 0;
	p = l - 1;
	x = 0;
	while (x < l)
	{
		ans = (ar[p] * (power)) + ans;
		p--;
		power = power * 10;
		x++;
	}
	return (ans);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
		return (0);
	}
}
