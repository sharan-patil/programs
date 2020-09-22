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

int	get_next_line(const int fd, char **line)
{
	static s_variables x;
	int len;

	if (fd < 0 || line == NULL || read(fd, x.text, 0))
		return (-1);
	len = 0;
	line[0] = (char*)malloc(1000);
	if (x.count == 0)
	{
		x.bytes_read = read(fd, x.text, BUFF_SIZE);
	}
	while (x.count < x.bytes_read)
	{
		if (x.text[x.count] != '\n')
		{
			line[0][len] = x.text[x.count];
			x.saved_fd = 1;
		}
		else
		{
			line[0][len] = '\0';
			x.saved_fd = 0;
		}
		x.count++;
		len++;
		if (x.saved_fd == 0)
		{
			if (x.count == x.bytes_read)
			{
				x.count = 0;
			}
			return (1);
		}
		if (x.count == x.bytes_read)
		{
			x.bytes_read = read(fd, x.text, BUFF_SIZE);
			x.count = 0;
			if (x.bytes_read == 0)
			{
				if (x.saved_fd == 1)
				{
					return (1);
				}
				return (0);
			}
		}
	}
	return (0);
}
