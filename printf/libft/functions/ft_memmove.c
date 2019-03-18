/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:17:55 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:17:57 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dist;
	char	*sour;
	size_t	i;

	i = -1;
	sour = (char*)src;
	dist = dest;
	if (sour < dist)
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			dist[i] = sour[i];
			i--;
		}
	}
	else
	{
		while (++i < n)
			dist[i] = sour[i];
	}
	return (dest);
}
