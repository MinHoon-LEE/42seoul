/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:24:55 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 16:17:17 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (dest == 0 && src == 0)
		return (0);
	i = -1;
	while (++i < n)
		*(char *)(dest + i) = *(char *)(src + i);
	return (dest);
}
