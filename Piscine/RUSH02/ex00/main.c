/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanlee <chanlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 22:39:12 by chanlee           #+#    #+#             */
/*   Updated: 2021/03/14 23:16:45 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>
#include <string.h>

void	check_array(char **key_arr, char **value_arr, char *arg)
{
	if (check_all_key(key_arr) == -1 || check_all_value(value_arr) == -1)
		write(1, "Dict Error\n", 11);
	else if (write_num(arg) == 0)
		write(1, "Error\n", 6);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		n;
	int		count;
	char	buf[5];

	if (!(argc >= 2 && argc <= 3))
		write(1, "Error\n", 6);
	else
	{
		count = countline(argc, argv);
		fd = input(argc, argv);
		g_value = 0;
		g_key = 0;
		if (fd == -1)
			write(1, "Dict Error\n", 11);
		else
		{
			create_double_array(count);
			while ((n = read(fd, buf, sizeof(buf))) > 0)
				buf_to_array(buf, n);
			check_array(g_key_arr, g_value_arr, number(argc, argv));
			close(fd);
			free_arr();
		}
	}
}
