/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:55:04 by minlee            #+#    #+#             */
/*   Updated: 2021/03/14 23:16:18 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	create_double_array(int count)
{
	int		n;

	n = 0;
	g_key_arr = malloc(sizeof(char **) * (g_max + 1));
	g_value_arr = malloc(sizeof(char **) * (g_max + 1));
	while (n < count)
	{
		g_key_arr[n] = malloc(sizeof(char *) * 100);
		g_value_arr[n] = malloc(sizeof(char *) * 100);
		n++;
	}
}

void	insert_buf(char *buf, int m, int n)
{
	int		i;

	i = 0;
	if (g_status == 0)
	{
		while (n + i < m)
		{
			g_key_arr[g_index][g_key] = buf[n + i];
			i++;
			g_key++;
		}
		g_key_arr[g_index][g_key] = '\0';
		g_key = 0;
	}
	else
	{
		while (n + i < m)
		{
			g_value_arr[g_index][g_value] = buf[n + i];
			i++;
			g_value++;
		}
		g_value_arr[g_index][g_value] = '\0';
		g_value = 0;
	}
}

void	insert_buf_left(char *buf, int m, int n)
{
	int		i;

	i = 0;
	if (g_status == 0)
	{
		while (n + i < m)
		{
			g_key_arr[g_index][g_key] = buf[n + i];
			i++;
			g_key++;
		}
	}
	else
	{
		while (n + i < m)
		{
			g_value_arr[g_index][g_value] = buf[n + i];
			i++;
			g_value++;
		}
	}
}

void	buf_to_left(char *buf, int m, int n)
{
	if (m > n)
	{
		if (g_status == 0)
			insert_buf_left(buf, m, n);
		else
			insert_buf_left(buf, m, n);
	}
}

void	buf_to_array(char *buf, int size)
{
	int		n;
	int		m;

	m = 0;
	n = 0;
	while (m < size)
	{
		if (buf[m] == ':' && g_status == 0)
		{
			insert_buf(buf, m, n);
			g_status = 1;
			n = m + 1;
		}
		if (buf[m] == '\n' && g_status == 1)
		{
			insert_buf(buf, m, n);
			g_status = 0;
			n = m + 1;
			g_index++;
		}
		m++;
	}
	buf_to_left(buf, m, n);
}
