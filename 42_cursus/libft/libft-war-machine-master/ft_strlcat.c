/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:33:23 by minlee            #+#    #+#             */
/*   Updated: 2021/02/25 01:48:20 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	m;

	m = 0;
	n = 0;
	while (dest[n] != '\0')
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
