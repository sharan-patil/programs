#include "fillit.h"

int g_square = 2;
t_tetri g_blocks[26];
int g_numberOfTetriminos;
char g_canvas[104][104];
char lastLetterAdded;
int lastAddedPoint[26][2];

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

int	main(int argc, char **argv)
{
	int *arr;

	arr = (int*)malloc(2 * sizeof(int));
	g_blocks[0].letter = 'A';
	initializeCanvas();
	analyzePoints(argv[1]);
	movePointsLeft();
	movePointsUp();
	checkAtleastOneBlock();
	recursiveOne(0, 0, 0, arr);
	printCanvas();
	return (0);
}
