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

typedef	struct variables{
	long int i;
	long int bytes_read;
	long int count;
	char text[BUFF_SIZE + 1];
	int begin;
}s_variables;

int	get_next_line(const int fd, char **line)
{
	static s_variables x;
	int len;

	len = 0;
	line[0] = (char*)malloc(1000);
	if (x.begin == 0)
	{
		x.bytes_read = read(fd, x.text, BUFF_SIZE);
		x.begin++;
	}
	while (1)
	{
		while (x.count < x.bytes_read)
		{
			if (x.text[x.count] != '\n')
			{
				printf("x.text[x.count]: %c\n", x.text[x.count]);
				line[0][len] = x.text[x.count];
			}
			else
			{
				x.count = 0;
				return (1);
			}
			x.count++;
			len++;
		}
		if (x.count == x.bytes_read)
		{
			x.bytes_read = read(fd, x.text, BUFF_SIZE) + x.bytes_read;
			x.count = 0;
		}
	}
	return (0);
}

int	main(void)
{
	char **line;
	int i = 0;
	int fd = open("text", O_RDONLY);
	while (get_next_line(fd, line))
	{
		printf("line: %s\n", line[0]);
		i++;
	}
	close(fd);
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
