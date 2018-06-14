/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:24:30 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:24:31 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strnequ(char const *s1, char const *s2, size_t size)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (size == 0)
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while ((unsigned int)i < size)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
