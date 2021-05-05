/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:39:27 by minlee            #+#    #+#             */
/*   Updated: 2021/03/10 18:06:23 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	long	size;
	int		*arr;
	int		n;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		*range = NULL;
		return (-1);
	}
	n = 0;
	*range = arr;
	while (n < size)
	{
		arr[n] = min + n;
		n++;
	}
	return (size);
}
