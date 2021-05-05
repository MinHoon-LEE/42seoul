/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:31:38 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 00:46:07 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	print_num(int tmp, int i)
{
	int		n;
	char	c;

	if (i > 0)
	{
		print_num(tmp / 16, i - 1);
		n = tmp % 16;
		if (n >= 10)
			c = 'a' + n - 10;
		else
			c = '0' + n;
		write(1, &c, 1);
	}
}

void	print_extra_num(int tmp, int i)
{
	int		n;
	char	c;

	if (i > 0)
	{
		print_num(tmp / 16, i - 1);
		n = tmp % 16;
		if (n >= 10)
			c = 'a' + n - 10;
		else
			c = '0' + n;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	print_word(char *arr)
{
	int				n;
	unsigned char	c;
	int				tmp;

	n = 0;
	while (n < 16)
	{
		c = (unsigned char)arr[n];
		write(1, " ", 1);
		tmp = c;
		p256(tmp / 16);
		p256(tmp % 16);
		n++;
	}
	write(1, "\n", 1);
}

void	echo_func(char *arr)
{
	print_num(g_index, 7);
	print_word(arr);
}

void	do_hex_echo(void)
{
	int		n;
	int		fd;
	char	buf[16];
	int		m;
	int		check;

	check = 0;
	g_error_flag = 1;
	fd = 0;
	while ((n = read(fd, buf, sizeof(buf))) > 0)
	{
		m = -1;
		while (++m < n)
		{
			do_hex_echo_sub(buf[m]);
			check = 1;
		}
	}
	if (g_tmp_index != 0)
		hex(g_tmp, g_tmp_index);
	g_index += g_tmp_index;
	if (check == 1)
		print_extra_num(g_index, 7);
}
