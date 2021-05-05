/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:52:32 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 01:05:45 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"
#include <stdio.h>

void	operation(long long x1, long long x2, unsigned char c)
{
	if (c == '+')
		do_plus(x1, x2);
	if (c == '-')
		do_minus(x1, x2);
	if (c == '*')
		do_multi(x1, x2);
	if (c == '/')
		do_div(x1, x2);
	if (c == '%')
		do_mod(x1, x2);
}

int		main(int argc, char **argv)
{
	unsigned char	c;
	long long		x1;
	long long		x2;

	c = (unsigned char)argv[2][0];
	if (argc == 4)
	{
		c = argv[2][0];
		x1 = ft_atoi(argv[1]);
		x2 = ft_atoi(argv[3]);
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		{
			operation(x1, x2, c);
			write(1, "\n", 1);
		}
		else
			write(1, "0\n", 2);
	}
	return (0);
}
