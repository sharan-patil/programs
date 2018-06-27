#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line)
{
	static char a[BUFF_SIZE + 1];
	static int i;
	static int count;
	static int prev_fd;
	static int bytes_read;
	int bytes_read_now;
	int j;

	printf("fd: %d\n", fd);
	if (fd < 0 || line == NULL || read(fd, a, 0))
		return (-1);
	if (i == 0)
		prev_fd = fd;
	if (prev_fd != fd)
	{
		count = 0;
		i = 0;
		prev_fd = fd;
		bytes_read = 0;
	}
	if (i == 0)
	{
		bytes_read_now = read(fd, &a[0], BUFF_SIZE);
		a[bytes_read_now] = '\0';
		bytes_read = bytes_read_now;
	}
	*line = (char*)malloc(100000);
	j = 0;
	while (1)
	{
		while (i < (BUFF_SIZE) * (count + 1))
		{
			if (a[i - (BUFF_SIZE * count)] == '\n')
			{
				i += 1;
				line[0][j] = '\0';
				if (i - 1 == bytes_read)
				{
					return (0);
				}
				return (1);
			}
			ft_strncpy(&line[0][j], &a[i - (BUFF_SIZE * count)], 1);
			i++;
			j++;
		}
		if (i - (BUFF_SIZE * count) == BUFF_SIZE)
		{
			bytes_read_now = read(fd, &a[0], BUFF_SIZE);
			bytes_read = bytes_read + bytes_read_now;
			count++;
		}
		if (!bytes_read_now)
		{
			return (0);
		}
	}
}

// int	main(void)
// {
// 	char **line;
// 	int fd;
// 	int eof;
// 	eof = 26;
// //	line = (char**)malloc(1);
// //	line[0] = (char*)malloc(10);
// 	fd = open("one_big_fat_line.txt", O_RDONLY);
// 	while (get_next_line(fd, line));
// 	printf("read: %zd\n", read(fd, NULL, 10));
// 	close(fd);
// 	return (0);
// }
