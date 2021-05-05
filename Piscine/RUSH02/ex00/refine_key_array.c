/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_key_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:26:45 by chanlee           #+#    #+#             */
/*   Updated: 2021/03/14 23:27:58 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		check_key_nl(char *key)
{
	if (if_only_nl_at_head(key) == -1)
		return (-1);
	else if (if_only_nl_at_head(key) == 1)
		trim_nl_at_head(key);
	return (0);
}

int		check_atoi_and_return_index(char *str)
{
	int i;
	int neg;
	int ret;
	int flag_zero;

	flag_zero = 0;
	i = 0;
	neg = 1;
	ret = 0;
	while (is_white_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] == '0')
	{
		flag_zero = 1;
		i++;
	}
	if (str[i] >= '1' && str[i] <= '9')
		return (i);
	else if (flag_zero == 1)
		return (-2);
	else
		return (-1);
}

int		check_one_key(char *key)
{
	int i;
	int start_i;

	if (check_key_nl(key) == -1)
		return (-1);
	if ((start_i = check_atoi_and_return_index(key)) == -2)
	{
		key[0] = '0';
		key[1] = 0;
	}
	else if (start_i == -1)
		return (-1);
	i = start_i;
	while (key[i] >= '0' && key[i] <= '9')
		i++;
	key[i] = 0;
	return (0);
}

int		all_key_overlap_check(char **key)
{
	int i;
	int j;

	i = 0;
	while (i + 1 < g_index)
	{
		j = i + 1;
		while (j < g_index)
		{
			if (ft_strcmp(key[i], key[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_all_key(char **key)
{
	int i;

	i = 0;
	while (i < g_index)
	{
		if (check_one_key(key[i]) == -1)
			return (-1);
		i++;
	}
	if (all_key_overlap_check(key) == -1)
		return (-1);
	return (0);
}
