/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:24:17 by minlee            #+#    #+#             */
/*   Updated: 2021/05/07 13:45:15 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// 이거 문자열의 끝까지만 비교해 줘야 되나  ? 
//
void	*ft_memchr(const void * ptr, int value, size_t num)
{
	size_t		i;

	i = -1;
	while (++i < num)
		if (*(unsigned char *)(ptr + i) == (unsigned char)value)
			break;
	if (i == num)
		return 0;
	else
		return ((void *)(ptr + i));
}
