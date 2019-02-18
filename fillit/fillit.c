#include "fillit.h"
#include <stdio.h>

int g_square = 2;

int	main(int argc, char **argv)
{
	t_tetri blocks[4];
	int fd;
	char buf[100];
	char arr[6];
	char arr2[6];
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	read(fd, buf, 5);
	buf[5] = '\0';
	printf("%s\n", buf);
	read(fd, buf, 5);
	buf[5] = '\0';
	printf("%s\n", buf);
	read(fd, buf, 5);
	buf[5] = '\0';
	printf("%s\n", buf);
	// while (read(fd, arr, 5))
	// {
	// 	i = 0;
	// 	printf("read: %s\n", arr);
	// 	while (i < 4)
	// 	{
	// 		if (arr[i] == '#')
	// 		{ // offsets but does not account for most top left block
	// 			blocks[k].pieceOffset[j][0] = j;
	// 			blocks[k].pieceOffset[j][1] = i;
	// 			printf("%d %d\n", j, i);
	// 		}
	// 		i++;
	// 	}
	// 	j++;
	// 	if (j == 4)
	// 	{
	// 		j = 0;
	// 		k++;
	// 		read(fd, 0, 1);
	// 	}
	// }
	close(fd);
	return (0);
}
