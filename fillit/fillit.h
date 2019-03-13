#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_tetrimino{
	int pieceOffset[4][2];
	char letter;
} t_tetri;

void exitError();
int	iterativeImp();
void checkAtleastOneBlock(int* arr);
void printPoints();
void movePointsUp();
void movePointsLeft();
void analyzePoints(char *file);
void initializeCanvas();
int	checkPoint(int x, int y, t_tetri aBlock);
int	*nextPoint(int x, int y, int* arr);
void printCanvas();
void addBlockOnCanvas(int x, int y, t_tetri aBlock);
void removeLastAddedBlock();
