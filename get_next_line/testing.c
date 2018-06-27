#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char a[BUFF_SIZE + 1];

	*line = (char*)malloc(50000);
	while ((bytes_read_now = read(fd, &a[0], BUFF_SIZE)) != 0)
	{
		a[bytes_read_now] = '\0';
		while (a[i] != '\n' && i < BUFF_SIZE)
		{
			*line[i] = a[i];
			i++;
		}
		if (a[i] == '\n')
		{
			*line[i] = '\0';
			return (1);
		}
		else
		{
			
		}
	}
}
