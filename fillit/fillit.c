#include "fillit.h"

int g_square = 2;
t_tetri g_blocks[26];
int g_numberOfTetriminos;
char g_canvas[104][104];
char lastLetterAdded;
int lastAddedPoint[26][2];

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
	recursiveOne(0, 0, 0, arr);
	printCanvas();
	return (0);
}
