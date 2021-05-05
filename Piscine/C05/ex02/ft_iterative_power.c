/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 07:03:23 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 07:04:20 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		sum;

	sum = 1;
	if (power < 0)
		return (0);
	else
	{
		if (power == 0)
			return (1);
		else
		{
			while (power > 0)
			{
				sum = nb * sum;
				power--;
			}
			return (sum);
		}
	}
}
