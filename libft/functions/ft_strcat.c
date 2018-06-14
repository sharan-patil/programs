/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:20:23 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:20:25 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dest, const char *src)
{
	int i;

	i = 0;
	while (*dest != '\0')
	{
		i++;
		dest++;
	}
	while (*src != '\0')
	{
		i++;
		*dest = (char)*src;
		dest++;
		src++;
	}
	i++;
	*dest = '\0';
	while (i != 1)
	{
		dest--;
		i--;
	}
	return (dest);
}
