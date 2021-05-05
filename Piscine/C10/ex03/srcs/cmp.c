/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:43:30 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 23:43:43 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		cmp(char *a, char *b)
{
	int		n;

	n = 0;
	while (n < 16)
	{
		if (a[n] != b[n])
			return (-1);
		n++;
	}
	return (0);
}