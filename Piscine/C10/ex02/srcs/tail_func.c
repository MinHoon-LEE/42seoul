/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:37:37 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 04:16:23 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	putstr(char *arr)
{
	int		n;

	n = 0;
	while (arr[n] != 0)
	{
		write(1, &arr[n], 1);
		n++;
	}
}

void	read_func(char *buf, long long size, int m, int n)
{
	int		index;

	index = n - (size - m);
	while (index < n)
	{
		write(1, &buf[index], 1);
		index++;
	}
}

void	tail_func(int fd, long long size, char *arr)
{
	int		n;
	char	buf[100];
	int		text_size;

	text_size = 0;
	while ((n = read(fd, buf, sizeof(buf))) > 0)
		text_size = text_size + n;
	close(fd);
	if (size >= text_size)
		print(arr, 1, NULL);
	else
	{
		fd = open(arr, O_RDONLY);
		while ((n = read(fd, buf, sizeof(buf))) > 0)
		{
			if (text_size - n < size)
			{
				read_func(buf, size, text_size - n, n);
				size = size - (size - (text_size - n));
			}
			text_size = text_size - n;
		}
	}
}
