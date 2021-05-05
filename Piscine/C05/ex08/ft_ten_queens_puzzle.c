/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 03:46:40 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 06:51:18 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		valid(int n, int m, int *queen)
{
	int		a;

	a = 0;
	while (a < n)
	{
		if (queen[a] == m)
			return (0);
		if ((n - a == queen[a] - m) || (n - a == m - queen[a]))
			return (0);
		a++;
	}
	return (1);
}

void	write_queen(int *queen)
{
	int		n;
	char	c;

	n = 0;
	while (n < 10)
	{
		c = '0';
		c = c + queen[n];
		write(1, &c, 1);
		n++;
	}
}

void	find(int n, int *queen, int *count)
{
	int		m;

	m = 0;
	if (n == 10)
	{
		*count += 1;
		write_queen(queen);
		write(1, "\n", 1);
	}
	else
	{
		while (m < 10)
		{
			if (valid(n, m, queen) == 1)
			{
				queen[n] = m;
				find(n + 1, queen, count);
			}
			m++;
		}
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		queen[10];
	int		count;

	count = 0;
	find(0, queen, &count);
	return (count);
}
