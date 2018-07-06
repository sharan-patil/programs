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
	static char a[BUFF_SIZE + 1];
	static int i;
	int j;
	int bytes_read_now;
	int flag;

	flag = 0;
	if (fd < 0 || line == NULL || read(fd, a, 0))
		return (-1);
	j = 0;
	line[0] = (char*)malloc(1000);
	if (i == 0)
	{
		bytes_read_now = read(fd, a, BUFF_SIZE);
		a[bytes_read_now] = '\0';
	}
	if (i == BUFF_SIZE)
	{
		bytes_read_now = read(fd, a, BUFF_SIZE);
		a[bytes_read_now] = '\0';
		i = 0;
		if (!bytes_read_now)
		{
			ft_bzero(a, BUFF_SIZE);
			return (0);
		}
	}
	while (i < BUFF_SIZE)
	{
		if (a[i] == '\n')
		{
			line[0][j] = '\0';
			i++;
			flag = 1;
		}
		else
		{
			line[0][j] = a[i];
			j++;
			i++;
		}
		if (flag)
		{
			return (1);
		}
	}
	// i = 0;
	// ft_bzero(a, BUFF_SIZE);
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
