/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:16:49 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:16:54 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*new;
	size_t	i;

	new = (char*)s;
	i = 1;
	while (i <= n)
	{
		if (*new == (char)c)
		{
			return (new);
		}
		i++;
		new++;
	}
	return (NULL);
}
