/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:26:19 by minlee            #+#    #+#             */
/*   Updated: 2021/02/22 13:27:24 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int		tmp[size];
	int		n;

	n = 0;
	while (n < size)
	{
		tmp[n] = tab[size - n - 1];
		n++;
	}
	while (size > 0)
	{
		tab[size - 1] = tmp[size - 1];
		size--;
	}
}
