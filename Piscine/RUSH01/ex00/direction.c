/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misong <misong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:30:28 by misong            #+#    #+#             */
/*   Updated: 2021/03/07 01:02:44 by geokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_col_up(int **arr, int col, int num)
{
	int i;
	int max;
	int count;

	i = 1;
	count = 1;
	max = arr[0][col];
	while (i < g_size)
	{
		if (arr[i][col] > max)
		{
			max = arr[i][col];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int		check_col_down(int **arr, int col, int num)
{
	int i;
	int max;
	int count;

	i = g_size - 2;
	count = 1;
	max = arr[g_size - 1][col];
	while (i >= 0)
	{
		if (arr[i][col] > max)
		{
			max = arr[i][col];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}

int		check_row_left(int **arr, int row, int num)
{
	int i;
	int max;
	int count;

	i = 1;
	count = 1;
	max = arr[row][0];
	while (i < g_size)
	{
		if (arr[row][i] > max)
		{
			max = arr[row][i];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int		check_row_right(int **arr, int row, int num)
{
	int i;
	int max;
	int count;

	i = g_size - 2;
	count = 1;
	max = arr[row][g_size - 1];
	while (i >= 0)
	{
		if (arr[row][i] > max)
		{
			max = arr[row][i];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}

int		ft_check_direction(int **arr, char *str)
{
	int i;
	int n;

	i = 0;
	n = g_size;
	while (str[i])
	{
		if (i >= 0 && i <= n - 1)
			if (!check_col_up(arr, i, str[i] - '0'))
				return (1);
		if (i >= n && i <= 2 * n - 1)
			if (!check_col_down(arr, i - n, str[i] - '0'))
				return (1);
		if (i >= 2 * n && i <= 3 * n - 1)
			if (!check_row_left(arr, i - 2 * n, str[i] - '0'))
				return (1);
		if (i >= 3 * n && i <= 4 * n - 1)
			if (!check_row_right(arr, i - 3 * n, str[i] - '0'))
				return (1);
		i++;
	}
	return (0);
}
