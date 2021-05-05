/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:30:19 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 01:30:20 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	tmp;
	int		tmp2;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		tmp = nb % 10 + '0';
		tmp2 = nb / 10;
		ft_putnbr(tmp2);
		write(1, &tmp, 1);
	}
	else
	{
		tmp = nb + '0';
		write(1, &tmp, 1);
	}
}
