/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:24:53 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:24:54 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int temp[4];

	temp[0] = -1;
	if (((temp[2] = ft_strlen(needle)) == 0))
		return ((char *)&haystack[0]);
	while (haystack[++temp[0]] != '\0' && temp[0] < (int)n)
	{
		if (haystack[temp[0]] == needle[0])
		{
			temp[1] = 0;
			temp[3] = temp[0];
			while (temp[1] < temp[2])
			{
				if (haystack[temp[3]] != needle[temp[1]])
					break ;
				temp[3]++;
				temp[1]++;
				if (temp[1] == temp[2])
					return ((char*)&haystack[temp[3] - temp[2]]);
				if (temp[0] + temp[1] > (int)n)
					return (NULL);
			}
		}
	}
	return (NULL);
}
