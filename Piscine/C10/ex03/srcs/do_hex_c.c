/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hex_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:44:04 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 04:24:44 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	print_word_c(char *arr)
{
	int				n;
	unsigned char	c;
	int				tmp;

	n = 0;
	while (n < 16)
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
}

void	print_c(char *arr)
{
	int				n;
	unsigned char	c;

	n = 0;
	write(1, "  |", 3);
	while (n < 16)
	{
		c = (unsigned char)arr[n];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		n++;
	}
	write(1, "|\n", 2);
}

void	echo_func_c(char *arr)
{
	print_num(g_index, 8);
	print_word_c(arr);
	print_c(arr);
}

void	do_hex_echo_c(void)
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
			do_hex_echo_c_sub(buf[m]);
			check = 1;
		}
	}
	if (g_tmp_index != 0)
		hex_c(g_tmp, g_tmp_index);
	g_index += g_tmp_index;
	if (check == 1)
		print_extra_num(g_index, 8);
}
