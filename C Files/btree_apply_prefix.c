/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:03:01 by spatil            #+#    #+#             */
/*   Updated: 2017/07/13 22:03:02 by spatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>
void applyf(void *a);
t_btree	*btree_create_node(void *item);

t_btree	*btree_create_node(void *item)
{
	t_btree *temp;

	temp = malloc(sizeof(t_btree));
	temp->item = item;
	temp->left = 0;
	temp->right = 0;
	return (temp);
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	t_btree *temp;

	temp = root;
	if (temp == 0)
		return ;
	applyf(temp->item);
	btree_apply_prefix(temp->left, applyf);
	btree_apply_prefix(temp->right, applyf);
}

int main(void)
{
	t_btree *head;
	int x = 10;
	head = btree_create_node(&x);
	int y = 20;
	t_btree *node1 = btree_create_node(&y);
	head->left = node1;
	btree_apply_prefix(head, applyf);
	printf("head->item: %d\n", *(int *)head->item);
	printf("node1->item: %d\n", *(int *)node1->item);
}

void applyf(void *a)
{
	int x;
	x = *(int *)a;
	x++;
	*(int *)a = x;
}
