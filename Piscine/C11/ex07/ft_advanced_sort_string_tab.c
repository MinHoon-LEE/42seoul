/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:10:09 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 00:31:20 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		n;
	int		m;
	int		size;

	size = 0;
	m = 0;
	n = 0;
	while (tab[size] != 0)
		size++;
	while (tab[n] != 0)
	{
		m = 0;
		while (m < size - 1 - n)
		{
			if ((*cmp)(tab[m], tab[m + 1]) > 0)
				swap(&tab[m], &tab[m + 1]);
			m++;
		}
		n++;
	}
}
