/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:57:50 by hyno              #+#    #+#             */
/*   Updated: 2021/03/14 23:26:58 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	write_0(int *spaceflag)
{
	int key_index;

	if ((key_index = find_index("0", 1)) != -1)
		ft_putstr(g_value_arr[key_index], spaceflag);
	write(1, "\n", 1);
}

void	write_999(char *str, int *spaceflag)
{
	char temp;

	if (str[0] >= '1')
	{
		ft_putstr(g_value_arr[find_index(&str[0], 1)], spaceflag);
		ft_putstr(g_value_arr[find_index("100", 3)], spaceflag);
	}
	if (str[1] >= '2')
	{
		temp = str[2];
		str[2] = '0';
		ft_putstr(g_value_arr[find_index(&str[1], 2)], spaceflag);
		str[2] = temp;
		if (str[2] > '0')
			ft_putstr(g_value_arr[find_index(&str[2], 1)], spaceflag);
	}
	if (str[1] == '1')
		ft_putstr(g_value_arr[find_index(&str[1], 2)], spaceflag);
	else if (str[1] == '0' && str[2] > '0')
		ft_putstr(g_value_arr[find_index(&str[2], 1)], spaceflag);
}

void	write_1000(int length, char *str, int *spaceflag)
{
	char	num1000[length + 1];
	int		i;
	int		key_index;

	if (str[0] > '0' || str[1] > '0' || str[2] > '0')
	{
		length -= 2;
		if (length <= 1)
			return ;
		num1000[0] = '1';
		num1000[length] = 0;
		i = 1;
		while (i < length)
			num1000[i++] = '0';
		if ((key_index = find_index(num1000, length)) != -1)
			ft_putstr(g_value_arr[key_index], spaceflag);
	}
}
