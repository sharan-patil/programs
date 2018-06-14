/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:25:34 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:25:35 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int temp[4];

	temp[2] = ft_strlen(needle);
	if ((temp[0] = -1) && needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[++temp[0]] != '\0')
	{
		if (haystack[temp[0]] == needle[0])
		{
			temp[1] = 0;
			temp[3] = temp[0];
			while (temp[1] < temp[2])
			{
				if (haystack[temp[3]] != needle[temp[1]])
					break ;
				temp[1]++;
				temp[3]++;
				if (temp[1] == temp[2])
					return ((char*)&haystack[temp[3] - temp[2]]);
			}
			temp[0]++;
			continue ;
		}
	}
	return (NULL);
}
