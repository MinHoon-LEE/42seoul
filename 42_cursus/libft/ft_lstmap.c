/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:28:13 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 19:28:48 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *start;
	t_list *tmp2;

	if (lst == 0 || f == 0)
		return (0);
	tmp2 = lst;
	start = 0;
	while (tmp2)
	{
		tmp = ft_lstnew((*f)(tmp2->content));
		if (tmp == 0)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, tmp);
		tmp2 = tmp2->next;
	}
	return (start);
}
