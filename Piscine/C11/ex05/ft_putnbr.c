/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:30:19 by minlee            #+#    #+#             */
/*   Updated: 2021/03/14 19:13:12 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(long long nb)
{
	char		tmp;
	long long	tmp2;

	if (nb < 0)
	{
		write(1, "-", 1);
		putnbr(-nb);
	}
	else if (nb >= 10)
	{
		tmp = nb % 10 + '0';
		tmp2 = nb / 10;
		putnbr(tmp2);
		write(1, &tmp, 1);
	}
	else
	{
		tmp = nb + '0';
		write(1, &tmp, 1);
	}
}
