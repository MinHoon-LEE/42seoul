/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:21:34 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 07:11:33 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		overlap(char *base)
{
	int		n;
	int		m;

	n = 0;
	while (base[n] != '\0')
	{
		m = 0;
		while (base[m] != '\0')
		{
			if (n != m)
			{
				if (base[n] == base[m])
					return (1);
			}
			m++;
		}
		n++;
	}
	return (0);
}

int		check_valid(char *base)
{
	int		n;
	int		check;

	n = 0;
	check = 0;
	while (base[n] != '\0')
	{
		if (base[n] == '-' || base[n] == '+')
			check = 1;
		if (base[n] == ' ' || base[n] == '\t' || base[n] == '\n')
			check = 1;
		if (base[n] == '\v' || base[n] == '\f' || base[n] == '\r')
			check = 1;
		n++;
	}
	if (overlap(base) == 1)
		check = 1;
	if (n == 0 || n == 1)
		check = 1;
	if (check == 1)
		return (1);
	return (0);
}

void	print(long nbr, int ba, char *base)
{
	if (nbr >= ba)
	{
		print(nbr / ba, ba, base);
		write(1, &base[nbr % ba], 1);
	}
	else
	{
		write(1, &base[nbr % ba], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		n;
	int		ba;
	long	tmp;

	ba = 0;
	n = 0;
	tmp = (long)nbr;
	if (check_valid(base) == 0)
	{
		n = 0;
		while (base[ba] != '\0')
			ba++;
		if (nbr < 0)
		{
			write(1, "-", 1);
			tmp = -(long)nbr;
		}
		print(tmp, ba, base);
	}
}
