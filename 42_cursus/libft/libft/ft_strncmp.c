/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:26:07 by minlee            #+#    #+#             */
/*   Updated: 2021/03/06 20:32:23 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	m;

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
