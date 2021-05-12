/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:55:16 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 19:14:02 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	tmp;
	int				tmp2;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		tmp = n % 10 + '0';
		tmp2 = n / 10;
		ft_putnbr_fd(tmp2, fd);
		write(fd, &tmp, 1);
	}
	else
	{
		tmp = n + '0';
		write(fd, &tmp, 1);
	}
}
