/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 22:37:45 by minlee            #+#    #+#             */
/*   Updated: 2021/03/18 04:07:10 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (*root != NULL)
	{
		if ((*cmpf)((*root)->item, item) > 0)
		{
			if ((*root)->left != NULL)
				btree_insert_data(&((*root)->left), item, cmpf);
			else
				(*root)->left = btree_create_node(item);
		}
		else
		{
			if ((*root)->right != NULL)
				btree_insert_data(&((*root)->right), item, cmpf);
			else
				(*root)->right = btree_create_node(item);
		}
	}
	else
		*root = btree_create_node(item);
}
