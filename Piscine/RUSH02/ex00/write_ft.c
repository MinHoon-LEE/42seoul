/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 23:39:38 by hyno              #+#    #+#             */
/*   Updated: 2021/03/14 22:05:53 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	write_num_sub(char *str, int length, int *spaceflag)
{
	char	num3[4];

	num3[3] = 0;
	if (length % 3 == 1)
	{
		num3[0] = '0';
		num3[1] = '0';
		num3[2] = str[0];
		length -= 1;
	}
	else if (length % 3 == 2)
	{
		num3[0] = '0';
		num3[1] = str[0];
		num3[2] = str[1];
		length -= 2;
	}
	write_999(num3, spaceflag);
	write_1000(length + 3, str, spaceflag);
}

int		check_num(char *str)
{
	int length;
	int i;

	length = ft_strlen(str);
	if (str[0] == '0' && length > 1)
		return (0);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		if (check_1000(length, &str[i]) == 0)
			return (0);
		i++;
		length--;
	}
	if (str[i])
		return (0);
	return (1);
}

int		write_num(char *str)
{
	int length;
	int spaceflag;

	if (check_num(str) == 0)
		return (0);
	spaceflag = 0;
	length = ft_strlen(str);
	if (length == 1 && str[0] == '0')
	{
		write_0(&spaceflag);
		return (1);
	}
	if (length % 3 != 0)
		write_num_sub(str, length, &spaceflag);
	str += length % 3;
	length -= length % 3;
	while (length > 0)
	{
		write_999(str, &spaceflag);
		write_1000(length, str, &spaceflag);
		str += 3;
		length -= 3;
	}
	write(1, "\n", 1);
	return (1);
}
