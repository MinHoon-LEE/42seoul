/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:26:07 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 20:48:51 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	m;

	m = 0;
	if (n == 0)
		return (0);
	else
	{
		while (m < n && s2[m] != '\0')
		{
			if ((unsigned char)s1[m] != (unsigned char)s2[m])
				return ((unsigned char)s1[m] - (unsigned char)s2[m]);
			m++;
		}
		if (m == n)
			return (0);
		else
			return ((unsigned char)s1[m] - (unsigned char)s2[m]);
	}
}
