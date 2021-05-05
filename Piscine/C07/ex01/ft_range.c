/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:33:39 by minlee            #+#    #+#             */
/*   Updated: 2021/03/10 17:51:20 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		size;
	int		*arr;
	int		n;

	n = 0;
	if (min >= max)
		return (0);
	else
	{
		size = max - min;
		arr = (int *)malloc(sizeof(int) * size);
		if (arr == NULL)
			return (0);
		while (n < size)
		{
			arr[n] = min + n;
			n++;
		}
		return (arr);
	}
}
