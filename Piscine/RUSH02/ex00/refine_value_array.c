/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refine_value_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:28:22 by chanlee           #+#    #+#             */
/*   Updated: 2021/03/14 23:29:07 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		is_nonprintable(char ch)
{
	if (!(ch >= 20 && ch <= 127))
		return (-1);
	return (0);
}

int		check_any_nonprintable_at_value(char *value)
{
	int i;
	int cnt;

	cnt = 0;
	i = 0;
	while (value[i])
	{
		if (is_nonprintable(value[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int		check_empty_value(char *value)
{
	int i;
	int cnt;

	cnt = 0;
	i = 0;
	while (value[i])
	{
		if (is_nonprintable(value[i]) == 0)
			cnt++;
		i++;
	}
	if (cnt == 0)
		return (-1);
	return (0);
}

void	trim_space_at_head(char *value)
{
	int i;

	i = 0;
	while (value[i] == ' ')
		i++;
	ft_strcpy(value, &value[i]);
}

int		check_all_value(char **value)
{
	int i;

	i = 0;
	while (i < g_index)
	{
		trim_space_at_head(value[i]);
		if (check_any_nonprintable_at_value(value[i]) == -1)
			return (-1);
		if (check_empty_value(value[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
