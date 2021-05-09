/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:53:02 by minlee            #+#    #+#             */
/*   Updated: 2021/05/07 13:23:50 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;

	i = -1;
	if (dest >= src)
		while (++i < n)
			*(char *)(dest + i) = *(char *)(src + i);
	else
		while (++i < n)
			*(char *)(dest + n - 1 - i) = *(char *)(src + n - 1 - i);
	return dest;
}
