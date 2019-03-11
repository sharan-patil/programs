#include "fillit.h"

extern int g_square;
extern t_tetri g_blocks[26];
extern int g_numberOfTetriminos;
extern char g_canvas[104][104];
extern char lastLetterAdded;
extern int lastAddedPoint[26][2];

/*
    An iterative backtracking algorithm which solves on g_canvas.
*/
int iterativeImp()
{
    int blockNumber;
    int *arr;

    arr = (int*)malloc(sizeof(int) * 2);
    blockNumber = 0;
    arr[0] = 0;
    arr[1] = 0;
    while (blockNumber != g_numberOfTetriminos)
    {
        if (arr[0] == -1 && arr[1] == -1)
        {
            if (lastLetterAdded <= '@')
            {
                g_square += 1;
                blockNumber = 0;
                arr[0] = 0;
                arr[1] = 0;
            }
            else
            {
                removeLastAddedBlock();
                blockNumber -= 1;
                arr = nextPoint(lastAddedPoint[blockNumber][0], lastAddedPoint[blockNumber][1], arr);
                lastLetterAdded -= 1;
            }
        }
        if (checkPoint(arr[0], arr[1], g_blocks[blockNumber]))
        {
            addBlockOnCanvas(arr[0], arr[1], g_blocks[blockNumber]);
            blockNumber += 1;
            arr[0] = 0;
            arr[1] = 0;
        }
        else
            arr = nextPoint(arr[0], arr[1], arr);
    }
    return 0;
}

/*
	Checks if the given point on the canvas can accomadate the given block.
*/
int	checkPoint(int x, int y, t_tetri aBlock)
{
	int i;

	i = 0;
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
	int i;

	i = 0;
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
	int i;
	int j;

	i = 0;
	j = 0;
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
