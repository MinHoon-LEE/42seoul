/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:33:23 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 17:51:25 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	m;

	m = 0;
	n = 0;
	while (dest[n] != '\0' && n < size)
		n++;
	if (n + 1 < size)
	{
		while (n + m + 1 < size && src[m] != '\0')
		{
			dest[n + m] = src[m];
			m++;
		}
		dest[n + m] = '\0';
	}
	while (src[m] != '\0')
		m++;
	if (size < n)
		return (size + m);
	else
		return (n + m);
}
