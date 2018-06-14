/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:11:39 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:11:42 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static	int		check(long int *tn, long int *positive, long int *temp,
	long int *len)
{
	if (tn[0] < 0)
	{
		positive[0] = 0;
		tn[0] *= -1;
	}
	while (temp[0] != 0)
	{
		temp[0] /= 10;
		temp[1]++;
	}
	len[0] = temp[1];
	return (0);
}

static	int		check2(char *new, long int *temp, long int *positive)
{
	if (temp[1] == 0)
	{
		new[0] = '0';
		new[1] = '\0';
		return (1);
	}
	if (!positive[0])
		new[0] = '-';
	temp[0] = 1;
	while (temp[2] < temp[1] - 1)
	{
		temp[0] *= 10;
		temp[2]++;
	}
	temp[1] = 0;
	return (0);
}

static	int		check3(long int *positive, long int *temp, long int *len)
{
	if (positive[0] == 0)
	{
		temp[1]++;
		len[0]++;
	}
	return (0);
}

static	int		check4(char *new, long int *temp, long int *len, long int *tn)
{
	while (temp[1] < len[0])
	{
		new[temp[1]] = tn[0] / temp[0] + 48;
		tn[0] %= temp[0];
		temp[0] /= 10;
		temp[1]++;
	}
	return (0);
}

char			*ft_itoa(int n)
{
	char		*new;
	long int	temp[3];
	long int	len[1];
	long int	positive[1];
	long int	tn[1];

	positive[0] = 1;
	tn[0] = (long int)n;
	temp[1] = 0;
	temp[0] = tn[0];
	temp[2] = 0;
	check(tn, positive, temp, len);
	len[0] = n == 0 ? len[0] + 1 : len[0];
	new = (char*)malloc(len[0] + 1 + !positive[0]);
	if (!new)
		return (NULL);
	if (check2(new, temp, positive) == 1)
		return (&new[0]);
	check3(positive, temp, len);
	check4(new, temp, len, tn);
	new[temp[1]] = '\0';
	return (&new[0]);
}
