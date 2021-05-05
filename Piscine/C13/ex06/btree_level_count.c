/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:44:41 by minlee            #+#    #+#             */
/*   Updated: 2021/03/18 03:52:11 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int		l_len;
	int		r_len;

	if (root == NULL)
		return (0);
	l_len = btree_level_count(root->left);
	r_len = btree_level_count(root->right);
	if (l_len > r_len)
		return (l_len + 1);
	else
		return (r_len + 1);
}
