/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:52:20 by minlee            #+#    #+#             */
/*   Updated: 2021/03/18 02:02:08 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree *head;

struct queue
{
	t_btree *node;
	int		level;
	queue	*next;
}

void btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first))
{
	queue *curr;
	curr = pop();
	(*applyf)(curr->node->item,curr->level);
	if (root->left != NULL)
		btree_apply_by_level(root->left, applyf(item);
}
