#include "fillit.h"

int g_square = 2;
t_tetri g_blocks[26];
int g_numberOfTetriminos;
char g_canvas[104][104];
char lastLetterAdded;
int lastAddedPoint[26][2];

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
	movePointsLeft();
	movePointsUp();
	checkAtleastOneBlock(arr);
	iterativeImp();
	printCanvas();
	return (0);
}
