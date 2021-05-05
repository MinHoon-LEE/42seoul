/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:02:13 by hyno              #+#    #+#             */
/*   Updated: 2021/03/14 22:46:03 by chanlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		input(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	if (argc == 3)
		fd = open(argv[1], O_RDONLY);
	return (fd);
}

char	*number(int argc, char **argv)
{
	if (argc == 2)
		return (argv[1]);
	else
		return (argv[2]);
}
