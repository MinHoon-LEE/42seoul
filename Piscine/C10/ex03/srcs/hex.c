/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:34:51 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 00:34:50 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	hex(char *buf, int n)
{
	print_num(g_index, 7);
	print_hex(buf, n);
}

void	print_hex(char *arr, int i)
{
	int				n;
	unsigned char	c;
	int				tmp;

	n = 0;
	while (n < i)
	{
		c = (unsigned char)arr[n];
		write(1, " ", 1);
		tmp = c;
		p256(tmp / 16);
		p256(tmp % 16);
		n++;
	}
	while (n++ < 16)
		write(1, "   ", 3);
	write(1, "\n", 1);
}

void	do_hex(int argc, char **argv, char *base, int index)
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
					do_hex_sub(buf[m]);
			}
			close(fd);
		}
		index++;
	}
	sub();
}
