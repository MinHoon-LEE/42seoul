/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:54:29 by minlee            #+#    #+#             */
/*   Updated: 2021/02/24 22:56:41 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_16(int a)
{
	char	c;

	if (a < 10)
	{
		c = '0' + a;
		write(1, &c, 1);
	}
	else
	{
		c = 'a' + a % 16 - 10;
		write(1, &c, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		n;
	int		num;
	int		a1;
	int		a2;

	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] < 32 || str[n] >= 127)
		{
			num = (unsigned char)str[n];
			a1 = num / 16;
			a2 = num % 16;
			write(1, "\\", 1);
			print_16(a1);
			print_16(a2);
		}
		else
		{
			write(1, &str[n], 1);
		}
		n++;
	}
}
