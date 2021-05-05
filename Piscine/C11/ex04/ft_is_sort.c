/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:30:21 by minlee            #+#    #+#             */
/*   Updated: 2021/03/14 18:30:50 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		n;
	int		status;
	int		curr_status;

	status = 0;
	n = -1;
	while (++n < length - 1)
	{
		curr_status = (*f)(tab[n], tab[n + 1]);
		if (curr_status > 0)
		{
			if (status >= 0)
				status = 1;
			else
				return (0);
		}
		if (curr_status < 0)
		{
			if (status <= 0)
				status = -1;
			else
				return (0);
		}
	}
	return (1);
}
