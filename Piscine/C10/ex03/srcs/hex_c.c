/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:14:25 by minlee            #+#    #+#             */
/*   Updated: 2021/03/17 18:35:44 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	hex_c(char *buf, int n)
{
	print_num(g_index, 8);
	print_hex_c(buf, n);
	print_c_hex(buf, n);
}

void	print_hex_c(char *arr, int i)
{
	int				n;
	unsigned char	c;
	int				tmp;

	n = 0;
	while (n < i)
	{
		c = (unsigned char)arr[n];
		if (n == 0 || n == 8)
			write(1, " ", 1);
		write(1, " ", 1);
		tmp = c;
		p256(tmp / 16);
		p256(tmp % 16);
		n++;
	}
	while (n < 16)
	{
		if (n == 0 || n == 8)
			write(1, " ", 1);
		write(1, "   ", 3);
		n++;
	}
}

void	print_c_hex(char *buf, int i)
{
	int				n;
	unsigned char	c;

	n = 0;
	write(1, "  |", 3);
	while (n < i)
	{
		c = (unsigned char)buf[n];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		n++;
	}
	write(1, "|\n", 2);
}

void	do_hex_c(int argc, char **argv, char *base, int index)
{
	int		n;
	int		fd;
	char	buf[16];
	int		m;

	while (index < argc)
	{
		fd = open(argv[index], O_RDONLY);
		if (fd == -1)
			error(errno, base, argv[index]);
		else
		{
			g_error_flag = 1;
			while ((n = read(fd, buf, sizeof(buf))) > 0)
			{
				m = -1;
				while (++m < n)
					do_hex_c_sub(buf[m]);
			}
			close(fd);
		}
		index++;
	}
	sub2();
}
