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
void checkAtleastOneBlock()
{
	int *arr;
	int i = 0;

	arr = (int*)malloc(2 * sizeof(int));
	arr[0] = 0;
	arr[1] = 0;
	while(i < g_square * g_square)
	{
		if (checkPoint(arr[0], arr[1], g_blocks[0]))
		{
			return ;
		}
		arr = nextPoint(arr[0], arr[1]);
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
	Uses recursive backtracking to figure out a square on the canvas.
*/
int	recursiveOne(int i, int j, int blockNumber, int *arr)
{
	if (arr[0] == -1 && arr[1] == -1)
	{
		if (lastLetterAdded == '@')
		{
			g_square += 1;
			blockNumber = 0;
			i = 0;
			j = 0;
		}
		else
		{
			removeLastAddedBlock();
			blockNumber -= 1;
			arr = nextPoint(lastAddedPoint[blockNumber][0], lastAddedPoint[blockNumber][1]);
			lastLetterAdded -= 1;
			return recursiveOne(arr[0], arr[1], blockNumber, arr);
		}
	}
	if (checkPoint(i, j, g_blocks[blockNumber]))
	{
		addBlockOnCanvas(i, j, g_blocks[blockNumber]);
		arr[0] = 0;
		arr[1] = 0;
		blockNumber += 1;
		if (blockNumber == g_numberOfTetriminos)
			return 0;
		return recursiveOne(arr[0], arr[1], blockNumber, arr);
	}
	else
	{
		arr = nextPoint(i, j);
		return recursiveOne(arr[0], arr[1], blockNumber, arr);
	}
}

void printPoints()
{
	int i;
	int j;

	i = 0;
	printf("-------------------------------------------\n");
	while (i < g_numberOfTetriminos)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d %d\n", g_blocks[i].pieceOffset[j][0], g_blocks[i].pieceOffset[j][1]);
			j++;
		}
		printf("Letter: %c\n", g_blocks[i].letter);
		printf("\n");
		i++;
	}
	printf("-------------------------------------------\n");
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
	Print current g_canvas.
*/
void printCanvas()
{
	int i = 0;
	int j = 0;

	while (i < g_square)
	{
		while (j < g_square)
		{
			printf("%c", g_canvas[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

/*
	Finds the next point on the canvas in top-left order.
*/
int	*nextPoint(int x, int y)
{
	int *arr;

	arr = (int*)malloc(2*sizeof(int));
	if (y == 0)
	{
		arr[0] = 0;
		arr[1] = x + y + 1;
	}
	else
	{
		arr[0] = x + 1;
		arr[1] = y - 1;
	}
	if (arr[0] > g_square - 1 || arr[1] > g_square - 1)
	{
		if (arr[0] > g_square - 1 && arr[0] + arr[1] == (2 * (g_square - 1)))
		{
			arr[0] = -1;
			arr[1] = -1;
			return arr;
		}
		else
			return nextPoint(arr[0], arr[1]);
	}
	return arr;
}

/*
	Checks if the given point on the canvas can accomadate the given block.
*/
int	checkPoint(int x, int y, t_tetri aBlock)
{
	int i = 0;

	while (i < 4)
	{
		if (x + aBlock.pieceOffset[i][0] > g_square - 1)
			return 0;
		if (y + aBlock.pieceOffset[i][1] > g_square - 1)
			return 0;
		if (g_canvas[x + aBlock.pieceOffset[i][0]][y + aBlock.pieceOffset[i][1]] != '.')
			return 0;
		i++;
	}
	return 1;
}

/*
	Adds the given block at the given point on the canvas.
	Use checkPoint() before this function as this does not perform
		a check on the canvas.
*/
void addBlockOnCanvas(int x, int y, t_tetri aBlock)
{
	int i = 0;

	lastLetterAdded = aBlock.letter;
	lastAddedPoint[lastLetterAdded - 65][0] = x;
	lastAddedPoint[lastLetterAdded - 65][1] = y;
	while (i < 4)
	{
		g_canvas[x + aBlock.pieceOffset[i][0]][y + aBlock.pieceOffset[i][1]] = lastLetterAdded;
		i++;
	}
}

/*
	Removes the block with letter equal to var lastLetterAdded from canvas.
*/
void removeLastAddedBlock()
{
	int i = 0;
	int j = 0;

	while (i < g_square)
	{
		while (j < g_square)
		{
			if (g_canvas[i][j] == lastLetterAdded)
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
void initializeCanvas()
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
