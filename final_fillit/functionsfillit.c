/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionsfillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:32 by spatil            #+#    #+#             */
/*   Updated: 2020/01/06 16:35:34 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int		g_square;
extern t_tetri	g_tet[26];
extern int		g_numoftet;
extern char		g_canvas[104][104];
extern char		g_lastletter;
extern int		g_lastpoint[26][2];

void	checkoneblock(int *arr)
{
	int i;

	i = 0;
	arr[0] = 0;
	arr[1] = 0;
	while (i < g_square * g_square)
	{
		if (checkpoint(arr[0], arr[1], g_tet[0]))
			return ;
		arr = nextpoint(arr[0], arr[1], arr);
		i++;
		if (i == g_square * g_square - 1)
		{
			i = 0;
			arr[0] = 0;
			arr[1] = 0;
			g_square += 1;
		}
	}
}

void	movepointsup()
{
	int i;

	i = 0;
	while (i < g_numoftet) {
		while (1) {
			if (g_tet[i].cor[0][0] - 1 > -1) {
				if (g_tet[i].cor[1][0] - 1 > -1) {
					if (g_tet[i].cor[2][0] - 1 > -1) {
						if (g_tet[i].cor[3][0] - 1 > -1) {
							g_tet[i].cor[0][0] -= 1;
							g_tet[i].cor[1][0] -= 1;
							g_tet[i].cor[2][0] -= 1;
							g_tet[i].cor[3][0] -= 1;
						}
						break ;
						}
					}
					break ;
					}
				}
				break ;
			}
		
		i++;
	}
}

/*
	Moves the values in global var to possible leftmost position.
*/
void	movepointsleft()
{
	int i;

	i = 0;
	while (i < g_numoftet)
	{
		while (1)
		{
			if (g_tet[i].cor[0][1] - 1 > -1)
			{
				if (g_tet[i].cor[1][1] - 1 > -1)
				{
					if (g_tet[i].cor[2][1] - 1 > -1)
					{
						if (g_tet[i].cor[3][1] - 1 > -1)
						{
							g_tet[i].cor[0][1] -= 1;
							g_tet[i].cor[1][1] -= 1;
							g_tet[i].cor[2][1] -= 1;
							g_tet[i].cor[3][1] -= 1;
						}
						else
						{
							break ;
						}
					}
					else
					{
						break ;
					}
				}
				else
				{
					break ;
				}
			}
			else
			{
				break ;
			}
		}
		i++;
	}
}

/*
	Reads the given file and traces the values of '#' character
		into global var g_tet.
	Traces exactly as given and does not account for most top left
		tetrimino in 4x4 area.
*/
void	analyzepoints(char *file)
{
	int fd;
	char arr[5];
	char newLine;
	int checker[6];
	int bytesRead;
	int totalBytesRead;

	totalBytesRead = 0;
	bytesRead = 0;
	checker[0] = 0;
	checker[5] = 0;
	checker[4] = 0;
	checker[2] = 0;
	fd = open(file, O_RDONLY);
	while ((bytesRead = read(fd, arr, 5)))
	{
		totalBytesRead += bytesRead;
		checker[3] = 0;
		while (checker[3] < 4)
		{
			if (arr[checker[3]] == '#')
			{
				g_tet[checker[4]].cor[checker[5]][0] = checker[2];
				g_tet[checker[4]].cor[checker[5]][1] = checker[3];
				checker[5]++;
				checker[5] %= 4;
				checker[0]++;
			}
			if (arr[checker[3]] != '#' && arr[checker[3]] != '.')
				exiterror();
			checker[3]++;
		}
		checker[2]++;
		if (checker[2] == 4)
		{
			if (checker[0] != 4)
				exiterror();
			if (checker[4] > 0)
				g_tet[checker[4]].letter = g_tet[checker[4] - 1].letter + 1;
			checker[0] = 0;
			checker[2] = 0;
			checker[4]++;
			checker[1] = read(fd, &newLine, 1);
			totalBytesRead += checker[1];
			if (newLine != '\n')
			{
				if (checker[1] != 0)
					exiterror();
			}
			g_numoftet++;
		}
	}
	if (g_numoftet == 0)
		exiterror();
	if (totalBytesRead != g_numoftet * 20 + g_numoftet - 1)
		exiterror();
	close(fd);
}

/*
	Finds the next point on the canvas in top-left order.
*/
int		*nextpoint(int x, int y, int* arr)
{
	if (y == g_square - 1)
	{
		if (x == g_square - 1)
		{
			arr[0] = -1;
			arr[1] = -1;
		}
		else
		{
			arr[0] = x + 1;
			arr[1] = 0;
		}
	}
	else
	{
		arr[0] = x;
		arr[1] = y + 1;
	}
	return arr;
}
