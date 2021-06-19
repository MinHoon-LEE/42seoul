/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:24:55 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 16:18:15 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;

	if (dest == 0 && src == 0)
		return (0);
	i = -1;
	while (++i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		if (*(char *)(src + i) == (char)c)
			break ;
	}
	if (i == n)
		return (0);
	else
		return (dest + i + 1);
}
