#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line)
{
	char *a;
	static int i;
	int bytes_read;
	int j;

	i = 0;
	while (1)
	{
		j = 0;
		a = (char*)malloc(sizeof(char) * BUFF_SIZE);
		bytes_read = read(fd, a, BUFF_SIZE);
		if (!bytes_read)
			return (-1);
		while (j < BUFF_SIZE)
		{
			if (a[i] == '\n' || a[i] == -1)
				return (0);
			line[0][i] = a[i];
			i++;
			j++;
		}
		free(a);
	}
	
}

// int	main(void)
// {
// 	char **line;
// 	int fd;

// 	fd = open("text", O_RDWR);
// 	line = (char**)malloc(1);
// 	line[0] = (char*)malloc(sizeof(char) * 15);
// 	get_next_line(fd, line);
// 	printf("line[0]: %s", line[0]);
// 	return (0);
// }