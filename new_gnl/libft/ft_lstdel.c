/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:12:02 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:12:05 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;
	t_list *temp;

	new = *alst;
	while (new->next != NULL)
	{
		temp = new->next;
		ft_lstdelone(&new, del);
		new = temp;
	}
	ft_lstdelone(&new, del);
	*alst = NULL;
}
