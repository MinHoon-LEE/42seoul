/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:28:00 by minlee            #+#    #+#             */
/*   Updated: 2021/05/13 15:18:40 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(sizeof(char) * 1);
		ptr[0] = 0;
		return (ptr);
	}
	if (start + len < ft_strlen(s))
		ptr = malloc(sizeof(char) * (len + 1));
	else
		ptr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (ptr == 0)
		return (0);
	while (i < len && *(s + i + (size_t)start) != 0)
	{
		*(ptr + i) = *(char *)(s + (size_t)start + i);
		i++;
	}
	*(ptr + i) = 0;
	return (ptr);
}
