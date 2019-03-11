#include "fillit.h"

extern int g_square;
extern t_tetri g_blocks[26];
extern int g_numberOfTetriminos;
extern char g_canvas[104][104];
extern char lastLetterAdded;
extern int lastAddedPoint[26][2];

/*
	Increases the value of g_square until atleast one block can fit.
*/
void checkAtleastOneBlock(int* arr)
{
	int i = 0;

	arr[0] = 0;
	arr[1] = 0;
	while(i < g_square * g_square)
	{
		if (checkPoint(arr[0], arr[1], g_blocks[0]))
			return ;
		arr = nextPoint(arr[0], arr[1], arr);
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

/*
	Moves the values in global var to possible topmost position.
*/
void movePointsUp()
{
	int i;

	i = 0;
	while (i < g_numberOfTetriminos)
	{
		while (1)
		{
			if (g_blocks[i].pieceOffset[0][0] - 1 > -1)
			{
				if (g_blocks[i].pieceOffset[1][0] - 1 > -1)
				{
					if (g_blocks[i].pieceOffset[2][0] - 1 > -1)
					{
						if (g_blocks[i].pieceOffset[3][0] - 1 > -1)
						{
							g_blocks[i].pieceOffset[0][0] -= 1;
							g_blocks[i].pieceOffset[1][0] -= 1;
							g_blocks[i].pieceOffset[2][0] -= 1;
							g_blocks[i].pieceOffset[3][0] -= 1;
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
	Moves the values in global var to possible leftmost position.
*/
void movePointsLeft()
{
	int i;

	i = 0;
	while (i < g_numberOfTetriminos)
	{
		while (1)
		{
			if (g_blocks[i].pieceOffset[0][1] - 1 > -1)
			{
				if (g_blocks[i].pieceOffset[1][1] - 1 > -1)
				{
					if (g_blocks[i].pieceOffset[2][1] - 1 > -1)
					{
						if (g_blocks[i].pieceOffset[3][1] - 1 > -1)
						{
							g_blocks[i].pieceOffset[0][1] -= 1;
							g_blocks[i].pieceOffset[1][1] -= 1;
							g_blocks[i].pieceOffset[2][1] -= 1;
							g_blocks[i].pieceOffset[3][1] -= 1;
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
		into global var g_blocks.
	Traces exactly as given and does not account for most top left
		tetrimino in 4x4 area.
*/
void analyzePoints(char *file)
{
	int fd;
	char arr[5];
	int i;
	int j;
	int k;
	int l;

	l = 0;
	k = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, arr, 5))
	{
		i = 0;
		while (i < 4)
		{
			if (arr[i] == '#')
			{
				g_blocks[k].pieceOffset[l][0] = j;
				g_blocks[k].pieceOffset[l][1] = i;
				l++;
				l %= 4;
			}
			i++;
		}
		j++;
		if (j == 4)
		{
			if (k > 0)
				g_blocks[k].letter = g_blocks[k - 1].letter + 1;
			j = 0;
			k++;
			read(fd, arr, 1);
			g_numberOfTetriminos++;
		}
	}
	close(fd);
}

/*
	Finds the next point on the canvas in top-left order.
*/
int	*nextPoint(int x, int y, int* arr)
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
