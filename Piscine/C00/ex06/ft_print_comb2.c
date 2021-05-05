/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:29:55 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 01:29:56 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_coma(void)
{
	char	m;
	char	n;

	m = ',';
	n = ' ';
	write(1, &m, 1);
	write(1, &n, 1);
}

void	print_num(char a, char b, char c, char d)
{
	char	n;

	n = ' ';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &n, 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_print1(char a1, char a2, char b1, char b2)
{
	while (b2 <= '9')
	{
		if (a1 <= b1)
		{
			if (a1 == b1)
			{
				if (a2 < b2)
				{
					if (a1 == '0' && a2 == '0' && b1 == '0' && b2 == '1')
						print_num(a1, a2, b1, b2);
					else
					{
						print_coma();
						print_num(a1, a2, b1, b2);
					}
				}
			}
			else
			{
				print_coma();
				print_num(a1, a2, b1, b2);
			}
		}
		b2++;
	}
}

void	ft_print_comb2(void)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	a1 = '0';
	while (a1 <= '9')
	{
		a2 = '0';
		while (a2 <= '9')
		{
			b1 = '0';
			while (b1 <= '9')
			{
				b2 = '0';
				ft_print1(a1, a2, b1, b2);
				b1++;
			}
			a2++;
		}
		a1++;
	}
}
