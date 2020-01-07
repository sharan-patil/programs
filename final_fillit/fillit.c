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

int				g_square = 2;
t_tetri			g_tet[26];
int				g_numoftet;
char			g_canvas[104][104];
char			g_lastletter;
int				g_lastpoint[26][2];

int				checkvicinity(int pnum, int bnum)
{
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < 4)
	{
		if (pnum != i)
		{
			if (g_tet[bnum].cor[pnum][0] == g_tet[bnum].cor[i][0])
			{
				if ((g_tet[bnum].cor[pnum][1] + 1 == g_tet[bnum].cor[i][1]) ||
				(g_tet[bnum].cor[pnum][1] - 1 == g_tet[bnum].cor[i][1]))
					j++;
			}
			if (g_tet[bnum].cor[pnum][1] == g_tet[bnum].cor[i][1])
			{
				if ((g_tet[bnum].cor[pnum][0] + 1 == g_tet[bnum].cor[i][0]) ||
				(g_tet[bnum].cor[pnum][0] - 1 == g_tet[bnum].cor[i][0]))
					j++;
			}
		}
	}
	return (j);
}

void			validtetriminos(void)
{
	int			i;
	int			j;
	int			sum;
	int			temp;

	temp = 0;
	sum = 0;
	i = 0;
	j = 0;
	while (i < g_numoftet)
	{
		while (j < 4)
		{
			if (!(temp = checkvicinity(j, i)))
				exiterror();
			sum += temp;
			j++;
		}
		if (sum != 6 && sum != 8)
			exiterror();
		sum = 0;
		i++;
		j = 0;
	}
}

void			exiterror(void)
{
	ft_putstr("error\n");
	exit(0);
}

void			printcanvas(void)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < g_square)
	{
		while (j < g_square)
		{
			ft_putchar(g_canvas[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

int				main(int argc, char **argv)
{
	int			*arr;

	if (argc != 2)
		return (0);
	arr = (int*)malloc(4 * sizeof(int));
	g_tet[0].letter = 'A';
	initializecanvas();
	analyzepoints(argv[1]);
	validtetriminos();
	movepointsleft();
	movepointsup();
	checkoneblock(arr);
	iterativeimp();
	printcanvas();
	return (0);
}
