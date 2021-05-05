/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hex2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:23:59 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 04:22:06 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	do_hex_echo_sub(char c)
{
	g_pre_tmp[g_tmp_index] = g_tmp[g_tmp_index];
	g_tmp[g_tmp_index] = c;
	g_tmp_index++;
	if (g_tmp_index == 16)
	{
		if (cmp(g_tmp, g_pre_tmp) != 0)
		{
			hex(g_tmp, 16);
			g_flag = 0;
		}
		else
		{
			if (g_flag == 0)
			{
				write(1, "*\n", 2);
				g_flag = 1;
			}
		}
		g_tmp_index = 0;
		g_index += 16;
	}
}

void	do_hex_echo_c_sub(char c)
{
	g_error_flag = 1;
	g_pre_tmp[g_tmp_index] = g_tmp[g_tmp_index];
	g_tmp[g_tmp_index] = c;
	g_tmp_index++;
	if (g_tmp_index == 16)
	{
		if (cmp(g_tmp, g_pre_tmp) != 0)
		{
			hex_c(g_tmp, 16);
			g_flag = 0;
		}
		else
		{
			if (g_flag == 0)
			{
				write(1, "*\n", 2);
				g_flag = 1;
			}
		}
		g_tmp_index = 0;
		g_index += 16;
	}
}

void	do_hex_sub(char c)
{
	g_pre_tmp[g_tmp_index] = g_tmp[g_tmp_index];
	g_tmp[g_tmp_index] = c;
	g_tmp_index++;
	if (g_tmp_index == 16)
	{
		if (cmp(g_tmp, g_pre_tmp) != 0)
		{
			hex(g_tmp, 16);
			g_flag = 0;
		}
		else
		{
			if (g_flag == 0)
			{
				write(1, "*\n", 2);
				g_flag = 1;
			}
		}
		g_index += 16;
		g_tmp_index = 0;
	}
}

void	do_hex_c_sub(char c)
{
	g_pre_tmp[g_tmp_index] = g_tmp[g_tmp_index];
	g_tmp[g_tmp_index] = c;
	g_tmp_index++;
	if (g_tmp_index == 16)
	{
		if (cmp(g_tmp, g_pre_tmp) != 0)
		{
			hex_c(g_tmp, 16);
			g_flag = 0;
		}
		else
		{
			if (g_flag == 0)
			{
				write(1, "*\n", 2);
				g_flag = 1;
			}
		}
		g_index += 16;
		g_tmp_index = 0;
	}
}
