/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 06:42:40 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 06:42:40 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char a);

void	print_bot(int hor, int x)
{
	if (hor == 0 || hor == x)
		putchar('C');
	else
		putchar('B');
}

void	print_top(int hor, int x)
{
	if (hor == 0 || hor == x)
		putchar('A');
	else
		putchar('B');
}

void	print(int hor, int ver, int x, int y)
{
	y--;
	x--;
	while (hor <= x)
	{
		if (ver == 0)
		{
			print_top(hor, x);
		}
		else if (ver == y)
		{
			print_bot(hor, x);
		}
		else
		{
			if (hor == 0 || hor == x)
				putchar('B');
			else
				putchar(' ');
		}
		hor++;
	}
}

void	rush(int x, int y)
{
	int		hor;
	int		ver;

	ver = 0;
	while (ver < y)
	{
		hor = 0;
		print(hor, ver, x, y);
		putchar('\n');
		ver++;
	}
}
