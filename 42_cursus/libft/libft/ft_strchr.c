/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:04:08 by minlee            #+#    #+#             */
/*   Updated: 2021/05/07 14:11:20 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char* str, int c)
{
	int		n;

	n = 0;
	while (1)
	{
		if (*(str + n) == (unsigned char)c)
			return (char *)(str+n);
		if (*(str + n) == 0)
			return (0);
		n++;
	}
	return (0);
}
