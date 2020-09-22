/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:35:32 by spatil            #+#    #+#             */
/*   Updated: 2020/01/06 16:35:34 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_tetrimino{
	int			cor[4][2];
	char		letter;
}				t_tetri;

void			exiterror();
int				iterativeimp();
void			checkoneblock(int *arr);
void			printpoints();
void			movepointsup();
void			movepointsleft();
void			analyzepoints(char *file);
void			initializecanvas();
int				checkpoint(int x, int y, t_tetri ablock);
int				*nextpoint(int x, int y, int *arr);
void			printcanvas();
void			addblock(int x, int y, t_tetri ablock);
void			removelastblock();

#endif
