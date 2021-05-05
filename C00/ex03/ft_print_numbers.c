/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 01:28:24 by minlee            #+#    #+#             */
/*   Updated: 2021/02/21 01:28:25 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	first;

	first = '0';
	while (first <= '9')
	{
		write(1, &first, 1);
		first++;
	}
}
