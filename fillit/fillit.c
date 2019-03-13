#include "fillit.h"

int g_square = 2;
t_tetri g_blocks[26];
int g_numberOfTetriminos;
char g_canvas[104][104];
char lastLetterAdded;
int lastAddedPoint[26][2];

int checkVicinity(int pointNumber, int blockNumber)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (pointNumber != i)
		{
			if (g_blocks[blockNumber].pieceOffset[pointNumber][0] == g_blocks[blockNumber].pieceOffset[i][0])
			{
				if (g_blocks[blockNumber].pieceOffset[pointNumber][1] + 1 == g_blocks[blockNumber].pieceOffset[i][1])
					j++;
				if (g_blocks[blockNumber].pieceOffset[pointNumber][1] - 1 == g_blocks[blockNumber].pieceOffset[i][1])
					j++;
			}
			if (g_blocks[blockNumber].pieceOffset[pointNumber][1] == g_blocks[blockNumber].pieceOffset[i][1])
			{
				if (g_blocks[blockNumber].pieceOffset[pointNumber][0] + 1 == g_blocks[blockNumber].pieceOffset[i][0])
					j++;
				if (g_blocks[blockNumber].pieceOffset[pointNumber][0] - 1 == g_blocks[blockNumber].pieceOffset[i][0])
					j++;
			}
		}
		i++;
	}
	return j;
}

void validTetriminos()
{
	int i;
	int j;
	int sum;
	int temp;

	temp = 0;
	sum = 0;
	i = 0;
	j = 0;
	while (i < g_numberOfTetriminos)
	{
		while (j < 4)
		{
			if (!(temp = checkVicinity(j, i)))
				exitError();
			sum += temp;
			j++;
		}
		if (sum != 6 && sum != 8)
			exitError();
		sum = 0;
		i++;
		j = 0;
	}
}

/*
	A function that prints error and quits the program.
*/
void exitError()
{
	ft_putstr("error\n");
	exit(0);
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
			ft_putchar(g_canvas[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	int *arr;

	if (argc != 2)
		return 0;
	arr = (int*)malloc(4 * sizeof(int));
	g_blocks[0].letter = 'A';
	initializeCanvas();
	analyzePoints(argv[1]);
	validTetriminos();
	movePointsLeft();
	movePointsUp();
	checkAtleastOneBlock(arr);
	iterativeImp();
	printCanvas();
	return (0);
}
