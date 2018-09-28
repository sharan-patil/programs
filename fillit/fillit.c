#include "fillit.h"

int	pieces_former(char* filename)
{
	int fd;
	char buf[4][4];
	int i;
	int j;

	j = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	while (read(fd, buf[i], 4))
	{
		while (j < 4)
		{
			if (buf[i][j] != '.')
			{

			}
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	node* root;
	char** give;

	give = malloc(1 * sizeof(char*));
	give[0] = malloc(1 * sizeof(char));
	root = (node*)malloc(sizeof(node*));
	root->fig = give;
	root->fig[0][2] = 's';
	return (0);
}