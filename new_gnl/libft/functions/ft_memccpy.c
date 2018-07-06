/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:16:35 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:16:37 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char*)dst;
	while (i < n)
	{
		*(dest + i) = *((unsigned char*)src + i);
		if (*((unsigned char*)src + i) == (unsigned char)c)
		{
			*(dest + i) = *((unsigned char*)src + i);
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
