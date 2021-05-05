/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:28:48 by minlee            #+#    #+#             */
/*   Updated: 2021/02/22 13:31:28 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	insert(int *a, int *b, int size)
{
	int		n;

	n = 0;
	while (n < size)
	{
		b[n] = a[n];
		n++;
	}
}

int		check1(int size, int *tab)
{
	int		min;
	int		n;
	int		m;
	int		index;

	n = 0;
	min = tab[0];
	index = 0;
	while (n < size)
	{
		if (min > tab[n])
		{
			min = tab[n];
			index = n;
		}
		n++;
	}
	while (index < size - 1)
	{
		tab[index] = tab[index + 1];
		index++;
	}
	return (min);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		tmp[size];
	int		n;
	int		m;
	int		min;

	m = size;
	n = 0;
	while (n < size)
	{
		min = check1(m, tab);
		m--;
		tmp[n] = min;
		n++;
	}
	insert(tmp, tab, size);
}
