#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line)
{
	static char a[BUFF_SIZE + 1];
	int i;
	int bytes_read_now;
	int j;

	if (fd < 0 || line == NULL || read(fd, a, 0))
		return (-1);
	i = 0;
	line[0] = (char*)malloc(50000);
	ft_bzero(*line, 50000);
	while ((bytes_read_now = read(fd, &a[0], BUFF_SIZE)) != 0)
	{
		j = 0;
		while (a[j] != '\n' && j < BUFF_SIZE)
		{
			line[0][i] = a[j];
			i++;
			j++;
		}
		if (a[j] == '\n')
		{
			line[0][i] = '\0';
			return (1);
		}
	}
	return (0);
}

int	main(void)
{
	int fd = open("text", O_RDONLY);
	char *line;
	int x = get_next_line(fd, &line);
	printf("x: %d\n", x);
	printf("line: %s\n", line);

	x = get_next_line(fd, &line);
	printf("x: %d\n", x);
	printf("line: %s\n", line);
	close(fd);
}
