/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:00:10 by hyno              #+#    #+#             */
/*   Updated: 2021/03/14 21:54:04 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int		ft_strncmp(char *str1, char *str2, int size)
{
	int	i;

	i = 0;
	while (i < size && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (str2[i] == 0 && i == size)
		return (0);
	return (-1);
}

void	ft_putstr(char *str, int *spaceflag)
{
	if (*spaceflag == 0)
		*spaceflag = 1;
	else
		write(1, " ", 1);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		find_index(char *str, int size)
{
	int i;

	i = 0;
	while (i < g_index && ft_strncmp(str, g_key_arr[i], size))
		i++;
	if (i == g_index)
		return (-1);
	return (i);
}

int		check_1000(int length, char *str)
{
	char	num1000[length + 1];
	int		i;

	if (length <= 3)
		return (1);
	if (length % 3 == 0 && str[0] == '0' && str[1] == '0' && str[2] == '0')
		return (1);
	if (length % 3 == 2 && str[0] == '0' && str[1] == '0')
		return (1);
	if (length % 3 == 1 && str[0] == '0')
		return (1);
	if (length % 3 == 0)
		length -= 3 - 1;
	else
		length -= length % 3 - 1;
	num1000[0] = '1';
	num1000[length] = 0;
	i = 1;
	while (i < length)
		num1000[i++] = '0';
	if (find_index(num1000, length) != -1)
		return (1);
	else
		return (0);
	return (1);
}
