/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:21:47 by minlee            #+#    #+#             */
/*   Updated: 2021/03/08 17:44:08 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *src)
{
	int		n;

	n = 0;
	while (src[n] != '\0')
		n++;
	return (n);
}

void	ft_cat(char *dest, char *src)
{
	int		dest_len;
	int		n;

	dest_len = 0;
	n = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[n] != '\0')
	{
		dest[dest_len + n] = src[n];
		n++;
	}
	dest[dest_len + n] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		n;
	char	*arr;
	int		sum;

	sum = 1;
	n = -1;
	if (size == 0)
		return ((char *)malloc(1));
	while (++n < size)
		sum = sum + ft_len(strs[n]);
	sum = sum + (size - 1) * ft_len(sep);
	arr = (char *)malloc(sum);
	if (arr == NULL)
		return (0);
	n = -1;
	arr[0] = '\0';
	while (++n < size)
	{
		ft_cat(arr, strs[n]);
		if (n != size - 1)
			ft_cat(arr, sep);
	}
	return (arr);
}
