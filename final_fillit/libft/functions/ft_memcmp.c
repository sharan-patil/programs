/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:17:12 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:17:14 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*n1;
	char	*n2;

	i = 1;
	n1 = (char*)s1;
	n2 = (char*)s2;
	while (i <= n)
	{
		if (*n1 == *n2)
		{
			n1++;
			n2++;
		}
		else
		{
			return ((unsigned char)*n1 - (unsigned char)*n2);
		}
		i++;
	}
	return ('\0');
}
