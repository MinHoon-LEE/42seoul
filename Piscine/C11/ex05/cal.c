/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 21:52:18 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 00:33:30 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	do_plus(long long x1, long long x2)
{
	int result;

	result = x1 + x2;
	putnbr(result);
}

void	do_minus(long long x1, long long x2)
{
	int result;

	result = x1 - x2;
	putnbr(result);
}

void	do_multi(long long x1, long long x2)
{
	int result;

	result = x1 * x2;
	putnbr(result);
}

void	do_div(long long x1, long long x2)
{
	int result;

	if (x2 == 0)
		write(1, "Stop : division by zero", 23);
	else
	{
		result = x1 / x2;
		putnbr(result);
	}
}

void	do_mod(long long x1, long long x2)
{
	int result;

	if (x2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else
	{
		result = x1 % x2;
		putnbr(result);
	}
}
