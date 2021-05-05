/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:21:03 by jasong            #+#    #+#             */
/*   Updated: 2021/03/18 05:24:59 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int		**make_c_map(char **map, char obs, int line, int row)
{
	int		**c_map;
	int		i;
	int		j;

	i = -1;
	if (!(c_map = (int **)malloc(sizeof(int *) * (line + 1))))
		return (NULL);
	while (++i < line + 1)
		c_map[i] = (int *)malloc(sizeof(int) * (row + 1));
	i = -1;
	while (++i < line)
	{
		j = -1;
		while (++j < row)
		{
			c_map[i][j] = 1;
			if (map[i][j] == obs)
				c_map[i][j] = 0;
			if (i == line - 1)
				c_map[line][j] = -1;
		}
		c_map[i][j] = -1;
	}
	c_map[line][row] = -1;
	return (c_map);
}

int		find_min(int n1, int n2, int n3)
{
	int		min;

	min = n1 < n2 ? n1 : n2;
	min = min < n3 ? min : n3;
	return (min + 1);
}

void	make_max(int **c, int line, int row)
{
	int		i;
	int		j;

	i = 0;
	while (++i < line)
	{
		j = 0;
		while (++j < row)
		{
			if (c[i][j] != 0)
				c[i][j] = find_min(c[i - 1][j], c[i][j - 1], c[i - 1][j - 1]);
			else
				continue ;
		}
	}
}

int		find_max_index(int **c_map, int *n)
{
	int		i;
	int		j;

	i = -1;
	while (++i >= 0)
	{
		j = -1;
		while (++j >= 0)
		{
			if (c_map[i][j] == -1)
				break ;
			if (n[0] < c_map[i][j])
			{
				n[0] = c_map[i][j];
				n[1] = i;
				n[2] = j;
			}
		}
		if (c_map[i][0] == -1)
			break ;
	}
	if (n[0] == 0)
		return (0);
	return (1);
}

void	free_cmap(int **cmap, int line)
{
	int		i;

	i = 0;
	while (i < line + 1)
	{
		free(*(cmap + i));
		i++;
	}
	free(cmap);
}

void	fill_map(char **m, int **cm, int n[], char f_c)
{
	int		i;
	int		j;

	if (n[0] == 0)
		return ;
	i = n[1] - n[0];
	while (++i <= n[1])
	{
		j = n[2] - n[0];
		while (++j <= n[2])
			m[i][j] = f_c;
	}
}

void	ft_strcpy(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

int		main(int argc, char **argv)
{
	char **m;
	int **cmap;
	int	n[3];
	char obs = 'o';
	char no = '.';
	char fil = 'x';
	
	m = map(argv[1]); 

	return 0;
}
