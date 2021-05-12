/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:53:02 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 16:22:02 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	if (dest == 0 && src == 0)
		return (0);
	i = -1;
	if (dest <= src)
		while (++i < n)
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
	else
		while (++i < n)
			*(unsigned char *)(dest + n - 1 - i) = \
				*(unsigned char *)(src + n - 1 - i);
	return (dest);
}
