/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:45:39 by minlee            #+#    #+#             */
/*   Updated: 2021/05/07 13:54:40 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t		i;

	i = -1;
	while (++i < num)
	{
		if (*(unsigned char *)(ptr1 + i) != *(unsigned char *)(ptr2 + i))
			return (int)(*(unsigned char *)(ptr1 + i) - *(unsigned char *)(ptr2 + i));
	}
	return (0);
}
