/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:15:38 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:15:40 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (!lst)
		return (NULL);
	new = (t_list*)malloc(sizeof(lst));
	if (!new)
		return (NULL);
	temp = f(lst);
	new = temp;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = f(lst);
		temp = temp->next;
	}
	return (new);
}
