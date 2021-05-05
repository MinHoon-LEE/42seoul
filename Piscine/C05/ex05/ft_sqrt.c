/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 06:59:07 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 07:00:00 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long long	n;

	n = 0;
	while (1)
	{
		if (nb < n * n)
			return (0);
		else if (nb == n * n)
			return (n);
		else
			n++;
	}
}