/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 07:05:32 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 07:06:26 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		n;
	int		sum;

	n = 1;
	sum = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (n <= nb)
	{
		sum = sum * n;
		n++;
	}
	return (sum);
}
