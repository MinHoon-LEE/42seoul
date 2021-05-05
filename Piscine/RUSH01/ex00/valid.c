/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:05:46 by minlee            #+#    #+#             */
/*   Updated: 2021/03/06 23:49:09 by geokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		quater(char *str)
{
	int		n;

	n = 0;
	while (str[n] != 0)
		n++;
	if ((n + 1) % 8 == 0)
		return ((n + 1) / 8);
	else
		return (-1);
}

int		ft_get_size(char *str)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '0' + quater(str))
			cnt++;
		i++;
	}
	return (cnt / 4);
}

int		ft_is_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 1)
		{
			if (str[i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int		ft_check_valid(char *str)
{
	int		i;

	i = 0;
	if (quater(str) == -1)
		return (1);
	while (str[i])
	{
		if (i % 2 == 0)
			if (!(str[i] >= '1' && str[i] <= '0' + quater(str)))
				return (1);
		i++;
	}
	if (ft_is_space(str) == 1)
		return (1);
	if (!((i + 1) == 8 * quater(str)))
		return (1);
	return (0);
}

void	ft_remove_space(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((str[j - 1] && str[j]) || j == 0)
	{
		str[i] = str[j];
		i++;
		j += 2;
	}
	str[i] = '\0';
}
