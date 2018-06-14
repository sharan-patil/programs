/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:10:05 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:10:10 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		check(char *s, int i, int *positive)
{
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' ||
		s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	i = s[i] == '+' ? i + 1 : i;
	if (s[i] == '-')
	{
		if (s[i - 1] == '+' || s[i + 1] == '+')
			return (0);
		positive[0] = 0;
		i++;
	}
	return (i);
}

static	int		check2(char *s, int i, int *c, int *ans)
{
	while (s[i] != '\0')
	{
		if (s[i] >= 48 && s[i] <= 57)
			ans[0] = (ans[0] * 10) + s[i] - '0';
		else
			break ;
		c[0]++;
		i++;
	}
	return (i);
}

int				ft_atoi(const char *s)
{
	int i;
	int ans[1];
	int c[1];
	int positive[1];

	c[0] = 0;
	i = 0;
	ans[0] = 0;
	positive[0] = 1;
	i = check((char*)s, i, positive);
	i = check2((char*)s, i, c, ans);
	if (c[0] > 10 && !positive[0] &&
		(ans[0] > 100000000 || ans[0] < -100000000))
		return (0);
	else if (c[0] > 10 && positive[0] && (ans[0]
		> 100000000 || ans[0] < -100000000))
		return (-1);
	if (!positive[0])
		return (ans[0] * (-1));
	else
		return (ans[0]);
}
