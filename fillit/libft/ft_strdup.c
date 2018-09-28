/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:21:52 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:21:54 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*news;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	news = (char*)malloc(len + 1);
	if (!news)
		return (NULL);
	while (*s1 != '\0')
	{
		*news = (char)*s1;
		news++;
		s1++;
		i++;
	}
	*news = '\0';
	news++;
	while (i != -1)
	{
		news--;
		i--;
	}
	return (news);
}
