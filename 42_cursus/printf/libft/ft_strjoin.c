/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:21:47 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 18:35:17 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		n;
	size_t		i;
	char		*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	n = ft_strlen((const char *)s1) + ft_strlen((const char *)s2) + 1;
	ptr = malloc(sizeof(char) * n);
	if (ptr == 0)
		return (0);
	while (i < ft_strlen((const char *)s1) && s1 != 0)
	{
		*(ptr + i) = *(char *)(s1 + i);
		i++;
	}
	i = 0;
	while (i < ft_strlen((const char *)s2) && s2 != 0)
	{
		*(ptr + ft_strlen((const char *)s1) + i) = *(char *)(s2 + i);
		i++;
	}
	*(ptr + n - 1) = 0;
	return (ptr);
}
