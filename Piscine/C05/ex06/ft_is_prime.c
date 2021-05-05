/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:57:42 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 06:58:43 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long long	n;

	n = 0;
	while (1)
	{
		if (nb < n * n)
			return (n - 1);
		else if (nb == n * n)
			return (n);
		else
			n++;
	}
}

int		ft_is_prime(int nb)
{
	int		max;
	int		n;

	n = 2;
	if (nb < 2)
		return (0);
	max = ft_sqrt(nb);
	while (n <= max)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}
