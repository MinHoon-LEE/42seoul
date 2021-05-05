/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:31:16 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 00:39:36 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

int		main(int argc, char **argv)
{
	int		m;
	char	*base;

	m = 2;
	base = basename(argv[0]);
	input(argc, argv, base);
	if (g_error_flag == 0)
		error(9, base, argv[argc - 1]);
	return (0);
}
