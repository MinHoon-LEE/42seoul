/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:35:45 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 04:28:59 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

void	sub(void)
{
	if (g_tmp_index != 0)
		hex(g_tmp, g_tmp_index);
	g_index += g_tmp_index;
	if (g_error_flag == 1 && g_index > 0)
		print_extra_num(g_index, 7);
}

void	sub2(void)
{
	if (g_tmp_index != 0)
		hex_c(g_tmp, g_tmp_index);
	g_index += g_tmp_index;
	if (g_error_flag == 1 && g_index > 0)
		print_extra_num(g_index, 8);
}
