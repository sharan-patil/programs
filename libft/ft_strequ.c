/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:22:05 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:22:06 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (i < ft_strlen(s1))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
