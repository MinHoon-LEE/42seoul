/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:29:20 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 01:29:21 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num1(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	print_coma1(void)
{
	char	n;
	char	m;

	n = ',';
	m = ' ';
	write(1, &n, 1);
	write(1, &m, 1);
}

void	ft_print2(char a, char b, char c)
{
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				if (a != b && b != c && a != c && a < b && b < c)
				{
					if (a == '0' && b == '1' && c == '2')
						print_num1(a, b, c);
					else
					{
						print_coma1();
						print_num1(a, b, c);
					}
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	b = '0';
	c = '0';
	ft_print2(a, b, c);
}
