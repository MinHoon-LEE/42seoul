/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:46:59 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 03:49:51 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include "tail.h"

void	print_illegal(char *base, char *num)
{
	while (*base)
	{
		write(2, base, 1);
		base++;
	}
	write(2, " illegal offset --", 18);
	while (*num)
	{
		write(2, num, 1);
		num++;
	}
	write(2, "\n", 1);
}

int		ft_atoi(char *num)
{
	int		n;
	int		m;

	m = 0;
	n = 0;
	while (num[m] != 0)
	{
		if (!(num[m] >= '0' && num[m] <= '9'))
			return (-1);
		n = 10 * n + num[m] - '0';
		m++;
	}
	return (n);
}

void	print_basic_tail(char *arr, char *num, char *base)
{
	int			fd;
	long long	size;

	size = ft_atoi(num);
	if (size == -1)
	{
		print_illegal(base, num);
		return ;
	}
	fd = open(arr, O_RDONLY);
	if (fd == -1)
		error(errno, base, arr);
	else
	{
		tail_func(fd, size, arr);
		close(fd);
	}
}

void	check_print(int *check)
{
	if (*check == 0)
		*check = 1;
	else
		write(1, "\n", 1);
}

void	print_tail(char *arr, char *num, char *base, int *check)
{
	int			fd;
	long long	size;

	size = ft_atoi(num);
	if (size == -1)
	{
		print_illegal(base, num);
		return ;
	}
	fd = open(arr, O_RDONLY);
	if (fd == -1)
		error(errno, base, arr);
	else
	{
		check_print(check);
		write(1, "==> ", 4);
		putstr(arr);
		write(1, " <==\n", 5);
		tail_func(fd, size, arr);
		close(fd);
	}
}
