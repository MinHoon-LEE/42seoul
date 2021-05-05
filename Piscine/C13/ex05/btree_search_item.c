/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:40:04 by minlee            #+#    #+#             */
/*   Updated: 2021/03/18 04:15:06 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	if (root != NULL)
	{
		if (root->left != NULL)
			return (btree_search_item(root->left, data_ref, cmpf));
		if ((*cmpf)(root->item, data_ref) == 0)
			return (root);
		if (root->right != NULL)
			return (btree_search_item(root->right, data_ref, cmpf));
	}
	return (NULL);
}
