#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	malloc_again(char *line)
{
	char *temp;

	temp = malloc(BUFF_SIZE);
	line = temp;
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char a[BUFF_SIZE + 1];
	int i;
	int bytes_read_now;
	int j;
	int n;

	j = 0;
	n = 0;
	if (fd < 0 || line == NULL || read(fd, a, 0))
		return (-1);
	line[0] = (char*)malloc(50000);
	ft_bzero(line[0], 50000);
	i = 0;
	while (n < BUFF_SIZE)
	{
		if (a[n] == '\n')
		{
			n += 1;
			while (n < BUFF_SIZE)
			{
				printf("n: %d\n", n);
				line[0][i] = a[n];
				n++;
				i++;
			}
		}
		n += 1;
	}
	while ((bytes_read_now = read(fd, &a[0], BUFF_SIZE)) != 0)
	{
		j = 0;
		while (a[j] != '\n' && j < BUFF_SIZE)
		{
			line[0][i] = a[j];
			i++;
			j++;
		}
		if (a[j] == '\n' && j < BUFF_SIZE)
		{
			line[0][i] = '\0';
			return (1);
		}
	}
	if (a[0] != '\n' && j != 0)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int fd = open("text", O_RDONLY);
// 	char *line;
// 	int x;
// 	while (x = get_next_line(fd, &line))
// 	{
// 		printf("x: %d\n", x);
// 		printf("line: %s\n", line);
// 	}
// 	close(fd);
//  }
