/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misong <misong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:22:36 by misong            #+#    #+#             */
/*   Updated: 2021/03/07 00:51:37 by geokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

void	ft_display(int **arr)
{
	int x;
	int y;

	x = 0;
	while (x < g_size)
	{
		y = 0;
		while (y < g_size)
		{
			ft_putchar(arr[x][y] + '0');
			if (y != g_size - 1)
				ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}

int		**ft_create_board(void)
{
	int x;
	int y;
	int **arr;

	x = 0;
	if (!(arr = (int **)malloc(sizeof(int *) * g_size)))
		return (0);
	while (x < g_size)
	{
		if (!(arr[x] = (int *)malloc(sizeof(int) * g_size)))
			return (0);
		x++;
	}
	x = -1;
	while (++x < g_size)
	{
		y = -1;
		while (++y < g_size)
			arr[x][y] = 0;
	}
	return (arr);
}
