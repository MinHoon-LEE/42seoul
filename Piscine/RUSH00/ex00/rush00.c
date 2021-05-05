/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 06:39:47 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 06:39:48 by minlee           ###   ########.fr       */
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
				putchar('o');
			else
				putchar('-');
		}
		else
		{
			if (hor == 0 || hor == x)
				putchar('|');
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
