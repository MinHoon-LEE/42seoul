/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:05:42 by minlee            #+#    #+#             */
/*   Updated: 2021/03/17 15:53:33 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	error(int n, char *base, char *arr)
{
	char *ptr;

	ptr = strerror(n);
	while (*base)
	{
		write(2, base, 1);
		base++;
	}
	write(2, ": ", 2);
	while (*arr)
	{
		write(2, arr, 1);
		arr++;
	}
	write(2, ": ", 2);
	while (*ptr)
	{
		write(2, ptr, 1);
		ptr++;
	}
	write(2, "\n", 1);
}

void	print(char *arr, int check, char *base)
{
	int		n;
	int		fd;
	char	buf[30];

	fd = open(arr, O_RDONLY);
	if (check == 0)
		fd = 0;
	if (fd == -1)
		error(errno, base, arr);
	else
	{
		while ((n = read(fd, buf, sizeof(buf))) > 0)
		{
			if (check != 0)
				write(1, buf, n);
		}
		close(fd);
	}
}

void	ft_write(char c)
{
	if (c != 0)
		write(1, &c, 1);
}

void	ft_echo(char *num)
{
	int			n;
	int			m;
	int			tmp;
	char		*buf;

	buf = malloc(ft_atoi(num));
	m = 0;
	n = ft_atoi(num);
	while (m++ < n)
		buf[m] = 0;
	if (n == 0)
	{
		while ((m = read(0, &g_tmp1[0], 1)) > 0)
			;
		return ;
	}
	while ((m = read(0, &buf[g_index % n], 1)) > 0)
		g_index++;
	tmp = g_index % n - 1;
	m = tmp + 1;
	while (++tmp < n)
		ft_write(buf[tmp]);
	tmp = -1;
	while (++tmp < m)
		ft_write(buf[tmp]);
}

int		main(int argc, char **argv)
{
	int		m;
	char	*base;
	int		check;

	check = 0;
	m = 2;
	base = basename(argv[0]);
	if (argc == 3)
		ft_echo(argv[2]);
	else
	{
		if (argc == 4)
			print_basic_tail(argv[3], argv[2], base);
		else
		{
			while (++m < argc)
				print_tail(argv[m], argv[2], base, &check);
		}
	}
	return (0);
}
