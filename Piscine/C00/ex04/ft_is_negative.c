/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:28:54 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 01:28:55 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int num)
{
	char	n;
	char	p;

	n = 'N';
	p = 'P';
	if (num < 0)
		write(1, &n, 1);
	else
		write(1, &p, 1);
}
