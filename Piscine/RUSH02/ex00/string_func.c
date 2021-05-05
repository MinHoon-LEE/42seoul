/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyno <hyno@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:04:32 by hyno              #+#    #+#             */
/*   Updated: 2021/03/14 20:50:21 by hyno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		len(char *src)
{
	int		len;

	len = 0;
	while (src[len] != '\0')
		len++;
	return (len);
}

void	free_arr(void)
{
	int		n;

	n = 0;
	while (n < g_index + 1)
	{
		free(g_key_arr[n]);
		free(g_value_arr[n]);
		n++;
	}
	free(g_key_arr);
	free(g_value_arr);
}
