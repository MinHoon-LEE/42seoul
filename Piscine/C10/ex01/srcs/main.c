/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:57:47 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 04:03:34 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

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
			write(1, buf, n);
		close(fd);
	}
}

void	ft_echo(void)
{
	print(NULL, 0, NULL);
}

int		main(int argc, char **argv)
{
	int		m;
	char	*base;

	m = 0;
	base = basename(argv[0]);
	if (argc == 1)
		ft_echo();
	else
	{
		while (++m < argc)
			print(argv[m], 1, base);
	}
	return (0);
}
