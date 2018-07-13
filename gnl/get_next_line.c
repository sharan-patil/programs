/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:32:28 by spatil            #+#    #+#             */
/*   Updated: 2018/07/06 13:32:33 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line)
{
	static int i;
	static char a[BUFF_SIZE + 1];
	static int bytes_read_now;
	int j;

	j = 0;
	line[0] = (char*)malloc(10000);
	while (i < BUFF_SIZE)
	{
		if (i == 0)
		{
			bytes_read_now = read(fd, a, BUFF_SIZE);
			a[bytes_read_now] = '\0';
			if (!bytes_read_now)
				return (0);
		}
		if (a[i] == '\n')
		{
			i++;
			line[0][j] = '\0';
			// if (bytes_read_now < BUFF_SIZE)
			// {
			// 	i = 0;
			// 	return (0);
			// }
			if (i == BUFF_SIZE)
				i = 0;
			return (1);
		}
		if (i >= bytes_read_now)
		{
			i = 0;
			return (0);
		}
		line[0][j] = a[i];
		j++;
		i++;
		if (i == BUFF_SIZE)
		{
			i = 0;
		}
	}
	return (0);
}

// int	main(void)
// {
// 	char **new;
// 	int fd = open("text", O_RDONLY);
// 	int ret;
// 	while ((ret = get_next_line(fd, new)))
// 	{
// 		printf("new[0]: \'%s\' && ret = %d\n", new[0], ret);
// 	}
// 	close(fd);
// 	fd = open("text2", O_RDONLY);
// 	while ((ret = get_next_line(fd, new)))
// 	{
// 		printf("new[0]: \'%s\' && ret = %d\n", new[0], ret);
// 	}
// 	close(fd);
// 	return (0);
// }
