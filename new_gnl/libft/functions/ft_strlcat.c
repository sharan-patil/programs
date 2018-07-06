/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:22:49 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:22:50 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int i;
	int len_s;
	int len_d;

	i = 0;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dest);
	if (size < (unsigned int)len_d + 1)
		return (size + len_s);
	while (i < (int)size - len_d - 1 && src[i] != '\0')
	{
		dest[len_d + i] = src[i];
		i++;
	}
	dest[len_d + i] = '\0';
	return (len_d + len_s);
}
