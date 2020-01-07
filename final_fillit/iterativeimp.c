/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:32 by spatil            #+#    #+#             */
/*   Updated: 2020/01/06 16:35:34 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int g_square;
extern t_tetri g_tet[26];
extern int g_numoftet;
extern char g_canvas[104][104];
extern char g_lastletter;
extern int g_lastpoint[26][2];

/*
    An iterative backtracking algorithm which solves on g_canvas.
*/
int iterativeimp()
{
    int blockNumber;
    int *arr;

    arr = (int*)malloc(sizeof(int) * 2);
    blockNumber = 0;
    arr[0] = 0;
    arr[1] = 0;
    while (blockNumber != g_numoftet)
    {
        if (arr[0] == -1 && arr[1] == -1)
        {
            if (g_lastletter <= '@')
            {
                g_square += 1;
                blockNumber = 0;
                arr[0] = 0;
                arr[1] = 0;
            }
            else
            {
                removelastblock();
                blockNumber -= 1;
                arr = nextpoint(g_lastpoint[blockNumber][0], g_lastpoint[blockNumber][1], arr);
                g_lastletter -= 1;
            }
        }
        if (checkpoint(arr[0], arr[1], g_tet[blockNumber]))
        {
            addblock(arr[0], arr[1], g_tet[blockNumber]);
            blockNumber += 1;
            arr[0] = 0;
            arr[1] = 0;
        }
        else
            arr = nextpoint(arr[0], arr[1], arr);
    }
    return 0;
}

/*
	Checks if the given point on the canvas can accomadate the given block.
*/
int	checkpoint(int x, int y, t_tetri ablock)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (x + ablock.cor[i][0] > g_square - 1)
			return 0;
		if (y + ablock.cor[i][1] > g_square - 1)
			return 0;
		if (g_canvas[x + ablock.cor[i][0]][y + ablock.cor[i][1]] != '.')
			return 0;
		i++;
	}
	return 1;
}

/*
	Adds the given block at the given point on the canvas.
	Use checkpoint() before this function as this does not perform
		a check on the canvas.
*/
void addblock(int x, int y, t_tetri ablock)
{
	int i;

	i = 0;
	g_lastletter = ablock.letter;
	g_lastpoint[g_lastletter - 65][0] = x;
	g_lastpoint[g_lastletter - 65][1] = y;
	while (i < 4)
	{
		g_canvas[x + ablock.cor[i][0]][y + ablock.cor[i][1]] = g_lastletter;
		i++;
	}
}

/*
	Removes the block with letter equal to var g_lastletter from canvas.
*/
void removelastblock()
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_square)
	{
		while (j < g_square)
		{
			if (g_canvas[i][j] == g_lastletter)
				g_canvas[i][j] = '.';
            j++;
		}
        j = 0;
        i++;
	}
}

/*
	Initializes every element of g_canvas to '.' character.
*/
void initializecanvas()
{
	int i = 0;
	int j = 0;

	while (i < 104)
	{
		while (j < 104)
		{
			g_canvas[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
    }
}
