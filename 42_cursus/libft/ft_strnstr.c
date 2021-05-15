/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:31:59 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 19:42:51 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	func(const char *str, const char *to_find, size_t len)
{
	size_t	n;
	int		m;
	int		check;

	n = 0;
	while (str[n] != '\0' && n <= len - ft_strlen(to_find))
	{
		m = 0;
		if (str[n] == to_find[m])
		{
			check = 1;
			while (to_find[m] != '\0')
			{
				if (str[n + m] != to_find[m])
					check = 0;
				m++;
			}
			if (check == 1)
				break ;
		}
		n++;
	}
	if (n == len - ft_strlen(to_find) + 1)
		return (-1);
	return (n);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		n;

	if (*to_find == '\0')
		return (char *)(str);
	n = func(str, to_find, len);
	if (n == -1 || len == 0)
		return (0);
	else
	{
		if (str[n] == '\0')
			return (0);
		return (char *)(str + n);
	}
}
