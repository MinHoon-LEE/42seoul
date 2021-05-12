/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:52:33 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 16:32:46 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	src_len;

	if (dest == 0 && src == 0)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	n = 0;
	if (size == 0)
		return (src_len);
	while (n + 1 < size && src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (src_len);
}
