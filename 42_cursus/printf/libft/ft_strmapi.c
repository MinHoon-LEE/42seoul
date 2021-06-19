/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:28:18 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 18:27:28 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	n;
	char	*ptr;

	n = 0;
	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (0);
	while (n < len)
	{
		ptr[n] = (*f)(n, s[n]);
		n++;
	}
	ptr[len] = 0;
	return (ptr);
}
