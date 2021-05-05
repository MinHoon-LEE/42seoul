/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:40:14 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 23:40:53 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	error(int n, char *base, char *arr)
{
	char *ptr;

	ptr = strerror(n);
	while (*base)
	{
		write(2, base, 1);
		base++;
	}
	write(2, ": ", 2);
	while (*arr)
	{
		write(2, arr, 1);
		arr++;
	}
	write(2, ": ", 2);
	while (*ptr)
	{
		write(2, ptr, 1);
		ptr++;
	}
	write(2, "\n", 1);
}
