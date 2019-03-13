#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char g_arr[256];

int	main(int argc, char** args)
{
	int fd;
	int i;

	i = 0;
	fd = open(args[1], O_RDONLY);
	read(fd, g_arr, 255);
	g_arr[255] = '\0';
	while (g_arr[i] != '\0')
	{
		if (g_arr[i] > 65 && g_arr[i] <= 90)
			g_arr[i] -= 1;
		else if (g_arr[i] == 65)
			g_arr[i] = 90;
		else if (g_arr[i] > 97 && g_arr[i] <= 122)
			g_arr[i] -= 1;
		else if (g_arr[i] == 97)
			g_arr[i] = 122;
		i++;
	}
	printf("%s\n", g_arr);
	return (0);
}