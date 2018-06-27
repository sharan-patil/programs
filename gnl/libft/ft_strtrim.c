/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:25:59 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:26:00 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	void		check(char *s, int *count, char *new)
{
	while (count[3] <= count[1])
	{
		new[count[0]] = s[count[3]];
		count[3]++;
		count[0]++;
	}
	new[count[0]] = '\0';
}

char				*ft_strtrim(char const *s)
{
	int		count[4];
	char	*new;

	if (!s)
		return (NULL);
	count[2] = ft_strlen(s);
	count[0] = 0;
	count[1] = count[2] - 1;
	while (s[count[0]] == ' ' || s[count[0]] == '\n' || s[count[0]] == '\t')
		count[0]++;
	if (count[0] == count[2] && count[0] != 0)
	{
		new = (char*)malloc(1);
		*new = '\0';
		return (new);
	}
	while (s[count[1]] == ' ' || s[count[1]] == '\n' || s[count[1]] == '\t')
		count[1]--;
	new = (char*)malloc(count[1] - count[0] + 2);
	if (!new)
		return (NULL);
	count[3] = count[0];
	count[0] = 0;
	check((char*)s, count, new);
	return (new);
}
