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
