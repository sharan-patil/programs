/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:37:56 by spatil            #+#    #+#             */
/*   Updated: 2017/07/18 11:37:56 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		opener(char *filename);

int		columns(char *filename);

void	printer(char str[100][100], int lines);

void	ft_putchar(char *str);

void	reader(char str[100][100], int lines, char *filename);

int		solver(char myshit[100][100], char info[5], int x, int y, int a);

void	cleaner(char str[100][100]);

int		ft_max(int *tab, int length);

int		maxindex(int *ray);

int		maxvalue(int *ray, int length);

int		countx(char str[100][100]);

int		plssolve(char myshit[100][100], char info[5]);

char	g_str[100][100] = {{'\0'}};

int		xvalue[500] = {0};

int		yvalue[500] = {0};

int		xsinmyshit[500] = {0};

int		main(int argc, char **argv)
{
	int fd;
	char myshit[100][100];
	char info[5];

	if (argc != 2)
		return (99);
	fd = opener(argv[1]);
	read(fd, info, 5);
	reader(g_str, info[0] - 48, argv[1]);
	cleaner(myshit);
	plssolve(myshit, info);
	cleaner(myshit);
	solver(myshit, info, xvalue[maxvalue(xsinmyshit, 500)], yvalue[maxvalue(xsinmyshit, 500)], xsinmyshit[maxvalue(xsinmyshit, 500)]);
	printer(myshit, 9);
	return (0);
}

int		solver(char myshit[100][100], char info[5], int x, int y, int a)
{
	int count;
	int p;
	int q;
	int temp;
	int life;

	p = x;
	q = y;
	count = 1;
	temp = 1;
	life = 0;
	while (count <= a)
	{
		while (myshit[p][q] == info[1] && temp <= (a))
		{
			myshit[p][q] = info[3];
			q++;
			temp++;
		}
		life++;
		if (temp - 1 != a)
		{
			cleaner(myshit);
			solver(myshit, info, x, y, a - 1);
			return (p);
		}
		q = y;
		temp = 1;
		p++;
		count++;
	}
	//printer(myshit, 9);
	return (p);
}

void	cleaner(char str[100][100])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (g_str[x][y] != '\0')
	{
		while (g_str[x][y] != '\0')
		{
			str[x][y] = g_str[x][y];
			y++;
		}
		str[x][y] = '\0';
		x++;
		y = 0;
	}
}

int		maxvalue(int *ray, int length)
{
	int x;
	int ans;
	int maxindex;

	maxindex = 0;
	ans = 0;
	x = 0;
	while (x < length)
	{
		if (ray[x] > ans)
		{
			ans = ray[x];
			maxindex = x;
		}
		x++;
	}
	return (maxindex);
}

int		plssolve(char myshit[100][100], char info[5])
{
	int x;
	int y;
	int z;

	x = 0;
	y = 0;
	z = 0;
	while (x < info[0] - 48)
	{
		while (y < columns("text"))
		{
			solver(myshit, info, x, y, (info[0] - 48) * (info[0] - 48));
			xsinmyshit[z] = countx(myshit);
			xvalue[z] = x;
			yvalue[z] = y;
			cleaner(myshit);
			z++;
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
