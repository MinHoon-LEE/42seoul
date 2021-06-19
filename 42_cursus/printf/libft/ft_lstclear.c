/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:25:38 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 19:26:21 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst != 0)
	{
		while (*lst != 0)
		{
			tmp = (*lst)->next;
			if (del != 0)
				(*del)((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}
