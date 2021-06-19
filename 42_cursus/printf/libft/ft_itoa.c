/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:53:36 by minlee            #+#    #+#             */
/*   Updated: 2021/05/13 15:18:11 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count1(int tmp)
{
	int		count;

	count = 1;
	while (1)
	{
		tmp /= 10;
		if (tmp == 0)
			break ;
		count++;
	}
	return (count);
}

static void	calculate(char *ptr, int n, int count, int minus)
{
	while (n != 0)
	{
		ptr[count + minus - 1] = n % 10 + '0';
		n /= 10;
		count--;
	}
}

char		*ft_itoa(int n)
{
	int		count;
	char	*ptr;
	int		minus;

	minus = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		minus = 1;
	}
	count = count1(n);
	if ((ptr = malloc(sizeof(char) * count + 1 + minus)) == 0)
		return (0);
	ptr[count + minus] = 0;
	if (n == 0)
		ptr[0] = '0';
	calculate(ptr, n, count, minus);
	if (minus == 1)
		ptr[0] = '-';
	return (ptr);
}
