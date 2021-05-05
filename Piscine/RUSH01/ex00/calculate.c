/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geokim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:13:28 by geokim            #+#    #+#             */
/*   Updated: 2021/03/07 00:11:33 by geokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_calculate(int **arr, char *str, int x, int y)
{
	int	i;

	i = 1;
	while (true)
	{
		while (i <= g_size && ft_check_num(arr, i, x, y))
			i++;
		if (i <= g_size)
			arr[x][y] = i;
		else
		{
			arr[x][y] = 0;
			return (1);
		}
		if (x == g_size - 1 && y == g_size - 1)
		{
			if (ft_check_direction(arr, str))
				continue;
			else
				return (0);
		}
		if (ft_recursive(arr, str, x, y))
			continue;
		return (0);
	}
}

int		ft_recursive(int **arr, char *str, int x, int y)
{
	if (x == g_size - 1)
	{
		if (ft_calculate(arr, str, 0, y + 1))
			return (1);
	}
	else
	{
		if (ft_calculate(arr, str, x + 1, y))
			return (1);
	}
	return (0);
}

int		ft_check_num(int **arr, int i, int x, int y)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < g_size)
	{
		if (i == arr[row++][y])
			return (1);
	}
	while (col < g_size)
	{
		if (i == arr[x][col++])
			return (1);
	}
	return (0);
}
