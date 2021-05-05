/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:42:16 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 23:43:08 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	input(int argc, char **argv, char *base)
{
	if (argc == 1)
		do_hex_echo();
	if (argc == 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'C')
			do_hex_echo_c();
		else
			do_hex(argc, argv, base, 1);
	}
	if (argc >= 3)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'C')
			do_hex_c(argc, argv, base, 2);
		else
			do_hex(argc, argv, base, 1);
	}
}
