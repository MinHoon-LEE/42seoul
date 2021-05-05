/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:18:10 by minlee            #+#    #+#             */
/*   Updated: 2021/03/14 18:20:16 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f)(char*))
{
	int		n;
	int		count;

	count = 0;
	n = 0;
	while (n < length)
	{
		if ((*f)(tab[n]) != 0)
			count++;
		n++;
	}
	return (count);
}
