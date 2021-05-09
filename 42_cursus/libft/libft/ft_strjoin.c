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

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		n;
	size_t		i;
	char		*ptr;
	size_t		len_s1;
	size_t		len_s2;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen((const char *)s1);
	len_s2 = ft_strlen((const char *)s2);
	i = 0;
	n = len_s1 + len_s2 + 1;
	ptr = malloc(sizeof(char) * n);
	if (ptr == 0)
		return (0);
	while (i < len_s1 && s1 != 0)
	{
		*(ptr + i) = *(char *)(s1 + i);
		i++;
	}
	i = 0;
	while (i < len_s2 && s2 != 0)
	{
		*(ptr + len_s1 + i) = *(char *)(s2 + i);
		i++;
	}
	*(ptr + n - 1) = 0;
	return (ptr);
}

