/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:12:14 by spatil            #+#    #+#             */
/*   Updated: 2018/06/14 15:12:18 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	new = *alst;
	del(new->content, new->content_size);
	free(new);
	*alst = NULL;
}
