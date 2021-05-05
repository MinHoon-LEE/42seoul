/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:10:09 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 00:21:05 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		n;

	n = 0;
	while (s1[n] != '\0')
	{
		if (s1[n] != s2[n])
			return (s1[n] - s2[n]);
		n++;
	}
	if (s2[n] == '\0')
		return (0);
	else
		return (-s2[n]);
}

void	swap(char **a, char **b)
{
	char	*tmp;

	tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(tab[m], tab[m + 1]) > 0)
				swap(&tab[m], &tab[m + 1]);
			m++;
		}
		n++;
	}
}
