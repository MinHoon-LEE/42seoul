/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_key_array2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:26:47 by chanlee           #+#    #+#             */
/*   Updated: 2021/03/14 23:28:31 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((int)s1[i] - (int)s2[i]);
}

int		is_white_space(char ch)
{
	return (ch == 9 || (ch >= 11 && ch <= 13) || ch == 32);
}

int		if_only_nl_at_head(char *key)
{
	int i;
	int cnt_n;
	int	cnt_n_again;

	cnt_n = 0;
	i = 0;
	while (key[i])
	{
		if (key[i] == '\n')
			cnt_n++;
		i++;
	}
	if (cnt_n == 0)
		return (0);
	i = 0;
	cnt_n_again = 0;
	while (key[i] == '\n')
	{
		cnt_n_again++;
		i++;
	}
	if (cnt_n_again != cnt_n)
		return (-1);
	return (1);
}

int		trim_nl_at_head(char *key)
{
	int i;

	i = 0;
	while (key[i] == '\n')
		i++;
	ft_strcpy(key, &key[i]);
	return (0);
}
