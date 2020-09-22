/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:17:23 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:17:24 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*des;
	char	*sour;
	size_t	i;

	i = 1;
	des = dest;
	sour = (char *)src;
	while (i <= n)
	{
		*des = *sour;
		i++;
		des++;
		sour++;
	}
	return (dest);
}
