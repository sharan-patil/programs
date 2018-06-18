#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libft.h>

int	get_next_line(const int fd, char **line)
{
	char a[BUFF_SIZE + 1];
	char *temp, *try;
	static int i;
	int bytes_read;
	int j;

	i = 0;
	while (1)
	{
		j = 0;
		bytes_read = read(fd, a, BUFF_SIZE);
		a[bytes_read] = '\0';
		strcpy(line[0], &a[0]);
		return (0);
		if (!bytes_read)
			return (-1);
		while (j < BUFF_SIZE)
		{
			if (a[j] == '\n' || a[j] == -1)
			{
				*line[i] = '\0';
				return (0);
			}
			printf("here");
			*line[i] = a[j];
			i++;
			j++;
		}
		line[i] = (char*)malloc(sizeof(char) * BUFF_SIZE);
	}
}

int	main(void)
{
	char **line;
	int fd;
//	line = (char**)malloc(1);
//	line[0] = (char*)malloc(10);
	fd = open("text", O_RDONLY);
	get_next_line(fd, line);
	printf("*line: %s\n", *line);
	return (0);
}
