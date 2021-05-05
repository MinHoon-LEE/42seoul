/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:27:21 by minlee            #+#    #+#             */
/*   Updated: 2021/03/10 12:09:56 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void					ft_putstr(char *str)
{
	int		n;

	n = 0;
	while (str[n] != 0)
	{
		write(1, &str[n], 1);
		n++;
	}
}

void					ft_atoi(int num)
{
	char	c;

	c = '0' + num % 10;
	if (num >= 10)
		ft_atoi(num / 10);
	write(1, &c, 1);
}

void					ft_show_tab(struct s_stock_str *par)
{
	int		n;

	n = 0;
	while (par[n].str != 0)
	{
		ft_putstr(par[n].str);
		write(1, "\n", 1);
		ft_atoi(par[n].size);
		write(1, "\n", 1);
		ft_putstr(par[n].copy);
		write(1, "\n", 1);
		n++;
	}
}
