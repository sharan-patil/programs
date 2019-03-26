#include <stdio.h>
#include <stdlib.h>

char board[3][3];

void printBoard()
{
	int i;
	int j;
	
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (j == 2)
				printf("%c\n", board[i][j]);
			else
				printf("%c | ", board[i][j]);
			j++;
		}
		i++;
	}
}

int* nextPoint(int* point)
{
	if (point[1] == 2)
	{
		point[1] = 0;
		point[0]++;
	}
	else
	{
		point[1]++;
	}
	while (point[0] < 3)
	{
		while (point[1] < 3)
		{
			if (board[point[0]][point[1]] == '\0')
				return point;
			point[1]++;
		}
		point[1] = 0;
		point[0]++;
	}
	point[0] = -1;
	point[1] = -1;
	return point;
}

int* analyzeBoard(int* point)
{
	point = nextPoint(point);
}

void makeMove(int* point)
{
	point = analyzeBoard(point);
	board[point[0]][point[1]] = 'x';
}

int	main(void)
{
	int x;
	int y;
	int *point;

	point = (int*)malloc(sizeof(int) * 2);
	point[0] = 0;
	point[1] = -1;
	while (1)
	{
		printBoard();
		printf("---------------\n");
		//printf("Row: ");
		//scanf("%d", &x);
		//printf("Column: ");
		//scanf("%d", &y);
		//board[x][y] = 'x';
		makeMove(point);
	//	checkWinner();
	}
}
