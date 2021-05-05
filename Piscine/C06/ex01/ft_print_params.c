/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 07:19:41 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 07:19:57 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *arr)
{
	int		n;

	n = 0;
	while (arr[n] != '\0')
	{
		write(1, &arr[n], 1);
		n++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char *argv[])
{
	int		n;

	n = 1;
	while (n < argc)
	{
		putstr(argv[n]);
		n++;
	}
}
