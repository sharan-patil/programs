/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 08:45:33 by spatil            #+#    #+#             */
/*   Updated: 2017/07/17 16:02:22 by spatil           ###   ########.fr       */
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

void	reader(char str[100][100], int lines, char *filename)
{
	int x;
	int fd;
	int cols;
	char info[5];

	cols = columns(filename);
	x = 0;
	fd = opener(filename);
	read(fd, info, 5);
	while (x < lines)
	{
		read(fd, str[x], cols);
		x++;
	}
}

void	printer(char str[100][100], int lines)
{
	int x;

	x = 0;
	while (x < lines)
	{
		ft_putchar(str[x]);
		x++;
	}
}

int		columns(char *filename)
{
	int x;
	int fd;
	char *check;
	int count;
	int temp;

	count = 0;
	x = 0;
	check = malloc(sizeof(char) * 200);
	fd = open(filename, O_RDONLY);
	read(fd, check, 5);
	while ((temp = read(fd, check, 2000)))
	{
		check[temp] = '\0';
		while (check[x] != '\0')
		{
			if (check[x] == '\n')
				return (count + 1);
			x++;
			count++;
		}
	}
	close(fd);
	return (count);
}

void	ft_putchar(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		write(1, &str[x], 1);
		x++;
	}
}

int		opener(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	return (fd);
}

int		countx(char str[100][100])
{
	int x;
	int y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while (str[x][y] != '\0')
	{
		while (str[x][y] != '\0')
		{
			if (str[x][y] == 'x')
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	return (count);
}
