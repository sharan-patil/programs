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
				g_blocks[checker[4]].pieceOffset[checker[5]][0] = checker[2];
				g_blocks[checker[4]].pieceOffset[checker[5]][1] = checker[3];
				checker[5]++;
				checker[5] %= 4;
				checker[0]++;
			}
			if (arr[checker[3]] != '#' && arr[checker[3]] != '.')
				exitError();
			checker[3]++;
		}
		checker[2]++;
		if (checker[2] == 4)
		{
			if (checker[0] != 4)
				exitError();
			if (checker[4] > 0)
				g_blocks[checker[4]].letter = g_blocks[checker[4] - 1].letter + 1;
			checker[0] = 0;
			checker[2] = 0;
			checker[4]++;
			checker[1] = read(fd, &newLine, 1);
			totalBytesRead += checker[1];
			if (newLine != '\n')
			{
				if (checker[1] != 0)
					exitError();
			}
			g_numberOfTetriminos++;
		}
	}
	if (g_numberOfTetriminos == 0)
		exitError();
	if (totalBytesRead != g_numberOfTetriminos * 20 + g_numberOfTetriminos - 1)
		exitError();
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
