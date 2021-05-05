/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:39:35 by minlee            #+#    #+#             */
/*   Updated: 2021/03/14 17:47:41 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		n;
	int		*arr;

	n = 0;
	arr = malloc(sizeof(int) * length);
	while (n < length)
	{
		arr[n] = (*f)(tab[n]);
		n++;
	}
	return (arr);
}
