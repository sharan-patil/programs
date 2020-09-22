/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:53:17 by spatil            #+#    #+#             */
/*   Updated: 2018/07/06 11:53:30 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <fcntl.h>

#define BUFF_SIZE 4

typedef	struct variables{
	int bytes_read;
	int count;
	char text[BUFF_SIZE + 1];
	int saved_fd;
}s_variables;

int	get_next_line(const int fd, char **line);

#endif
