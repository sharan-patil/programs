/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:25:21 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:25:24 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	void		initialise(int *count, int i)
{
	if (i == 1)
	{
		count[1] = 1;
		count[2] = 0;
		count[0] = 0;
		count[3] = 0;
	}
	if (i == 2)
	{
		count[0] = 1;
		count[2] = 0;
		count[1] = 0;
		count[3] = 0;
	}
}

static	void		check(char *s, int *count, int points[100][2], char c)
{
	while (s[count[0]] != '\0')
	{
		while (s[count[0]] == c)
			count[0]++;
		if (s[count[0]] == '\0')
			break ;
		points[count[1]][count[2]] = count[0];
		count[2]++;
		while (s[count[0]] != '\0' && s[count[0]] != c)
		{
			count[0]++;
			count[3]++;
		}
		points[count[1]][count[2]] = count[3];
		count[1]++;
		count[2] = 0;
		count[3] = 0;
	}
	points[0][0] = count[1];
}

static	void		check2(char *s, int *count, int points[100][2], char **new)
{
	while (count[3] < points[count[0]][1])
	{
		new[count[0] - 1][count[3]] = s[(points[count[0]][0] + count[3])];
		count[3]++;
	}
	new[count[0] - 1][count[3]] = '\0';
	count[3] = 0;
	count[0]++;
}

char				**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		count[4];
	int		points[100][2];

	initialise(count, 1);
	if (!s)
		return (NULL);
	check((char*)s, count, points, c);
	new = (char**)malloc(sizeof(char*) * points[0][0]);
	if (!new)
		return (NULL);
	initialise(count, 2);
	while (count[0] < points[0][0])
	{
		new[count[0] - 1] = (char*)malloc(sizeof(char) *
			(points[count[0]][1] + 1));
		if (!new[count[0] - 1])
			return (NULL);
		check2((char*)s, count, points, new);
	}
	new[count[0] - 1] = NULL;
	return (new);
}
