/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:55:00 by hyno              #+#    #+#             */
/*   Updated: 2021/03/14 23:15:40 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	maxlen(char c)
{
	g_max_curr++;
	if (c == '\n')
	{
		if (g_max_curr > g_max)
			g_max = g_max_curr;
		g_max_curr = 0;
	}
}

int		countline(int argc, char **argv)
{
	int		fd;
	int		m;
	int		count;
	int		n;
	char	buf[30];

	count = 0;
	fd = input(argc, argv);
	if (fd == -1)
		write(1, "Dict Error\n", 11);
	else
	{
		while ((n = read(fd, buf, sizeof(buf))) > 0)
		{
			m = -1;
			while (++m < n)
			{
				maxlen(buf[m]);
				if (buf[m] == ':')
					count++;
			}
		}
		close(fd);
	}
	return (count);
}
