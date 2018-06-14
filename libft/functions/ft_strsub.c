/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:25:45 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:25:46 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	new = (char*)malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && i < len + (int)start)
		{
			new[j] = s[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (&new[0]);
}
