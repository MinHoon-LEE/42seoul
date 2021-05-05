/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:26:59 by minlee            #+#    #+#             */
/*   Updated: 2021/03/08 14:30:39 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		n;
	char	*arr;

	n = 0;
	len = 0;
	while (src[n] != '\0')
	{
		len++;
		n++;
	}
	if (src[n] == '\0')
		len++;
	arr = (char *)malloc(sizeof(char) * len);
	n = 0;
	while (n < len)
	{
		arr[n] = src[n];
		n++;
	}
	return (arr);
}
