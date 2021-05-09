/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:13:03 by minlee            #+#    #+#             */
/*   Updated: 2021/05/07 14:48:29 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strlen(char *str)
{
	int		tmp;

	tmp = 0;
	while (str[tmp] != '\0')
	{
		tmp++;
	}
	return (tmp);
}

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen((char *)s);
	while (--len >= 0)
		if (*(s + len) == (char)c)
			break;
	if (len == -1)
		return (0);
	else
		return (char *)(s + len);
}
