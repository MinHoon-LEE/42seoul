/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:30:51 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 06:11:58 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_1[10];

void	check(int n)
{
	int		tmp;

	tmp = 0;
	while (tmp <= n)
	{
		write(1, &g_1[tmp], 1);
		tmp++;
	}
	if (g_1[0] != '9' - n)
		write(1, ", ", 2);
}

void	flag(int n, int m)
{
	while (n <= m)
	{
		g_1[n] = g_1[n - 1] + 1;
		n++;
	}
}

void	func(int n, int m)
{
	if (g_1[0] == '9' - m)
		check(m);
	else
	{
		if (g_1[n] < '9' + n - m)
		{
			check(m);
			g_1[n]++;
			flag(n + 1, m);
			func(m, m);
		}
		else
		{
			if (n - 1 >= 0)
				func(n - 1, m);
		}
	}
}

void	ft_print_combn(int n)
{
	int		tmp;
	int		tmp2;

	tmp = n - 1;
	tmp2 = 0;
	while (tmp2 < n)
	{
		g_1[tmp2] = '0' + tmp2;
		tmp2++;
	}
	func(tmp, n - 1);
}
