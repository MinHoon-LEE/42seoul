/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:37:03 by minlee            #+#    #+#             */
/*   Updated: 2021/03/08 23:44:01 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int						length(char *str)
{
	int		n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char					*ft_strdup(char *src)
{
	char	*arr;
	int		n;

	n = 0;
	arr = (char *)malloc(length(src) + 1);
	if (arr == NULL)
		return (0);
	while (src[n] != 0)
	{
		arr[n] = src[n];
		n++;
	}
	arr[n] = '\0';
	return (arr);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	int			n;
	t_stock_str *arr;

	n = 0;
	arr = (t_stock_str *)malloc((ac + 1) * 24);
	if (arr == NULL)
		return (0);
	while (n < ac)
	{
		arr[n].size = length(av[n]);
		arr[n].str = av[n];
		arr[n].copy = ft_strdup(av[n]);
		if (arr[n].copy == NULL)
			return (0);
		n++;
	}
	arr[n].str = 0;
	return (arr);
}
