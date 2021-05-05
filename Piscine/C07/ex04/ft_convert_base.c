/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:57:54 by minlee            #+#    #+#             */
/*   Updated: 2021/03/08 19:15:55 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		overlap(char *a);
int		check_valid(char *base);

void	insert(long sum, char *base_to, char *arr, int *index)
{
	int		len;

	len = 0;
	while (base_to[len] != '\0')
		len++;
	if (sum >= len)
	{
		insert(sum / len, base_to, arr, index);
		arr[*index] = base_to[sum % len];
		*index = *index + 1;
	}
	else
	{
		arr[*index] = base_to[sum % len];
		*index = *index + 1;
	}
}

void	func(long sum, char *base_to, char *arr)
{
	int index;

	index = 0;
	if (sum < 0)
	{
		sum = -sum;
		arr[0] = '-';
		index = 1;
	}
	insert(sum, base_to, arr, &index);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	sum;
	int		result;
	char	*arr;
	int		len;

	len = 0;
	result = 2;
	if (check_valid(base_from) == 1 || check_valid(base_to) == 1)
		return (0);
	sum = ft_atoi_base(nbr, base_from);
	while (base_to[len] != '\0')
		len++;
	while (sum / len != 0)
	{
		sum = sum / len;
		result++;
	}
	if (sum < 0)
		result++;
	arr = (char *)malloc(result);
	sum = ft_atoi_base(nbr, base_from);
	func(sum, base_to, arr);
	arr[result - 1] = '\0';
	return (arr);
}
