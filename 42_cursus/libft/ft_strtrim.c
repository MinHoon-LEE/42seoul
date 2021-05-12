/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:35:49 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 18:36:19 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	i = 0;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	while (s1[i] != 0 && ft_strchr(set, s1[i]))
		i++;
	while (j > 0 && ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	ptr = malloc(sizeof(char) * (j - i + 2));
	if (ptr == 0)
		return (0);
	ft_strlcpy(ptr, s1 + i, j - i + 2);
	return (ptr);
}
