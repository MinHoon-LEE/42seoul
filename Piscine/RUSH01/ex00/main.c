/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misong <misong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:02:21 by misong            #+#    #+#             */
/*   Updated: 2021/03/07 01:06:46 by geokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	int **arr;

	if (argc != 2)
		return (ft_error());
	g_size = ft_get_size(argv[1]);
	if (ft_check_valid(argv[1]))
		return (ft_error());
	ft_remove_space(argv[1]);
	if (!(arr = ft_create_board()))
		return (ft_error());
	if (ft_calculate(arr, argv[1], 0, 0))
		return (ft_error());
	ft_display(arr);
	free(arr);
	return (1);
}
