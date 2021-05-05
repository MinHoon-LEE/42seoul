/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 06:43:07 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 06:43:08 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char a);

void	print(int hor, int ver, int x, int y)
{
	y--;
	x--;
	while (hor <= x)
	{
		if (ver == 0 || ver == y)
		{
			if (hor == 0 || hor == x)
				if (hor == 0)
					putchar('A');
				else
					putchar('C');
			else
				putchar('B');
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
