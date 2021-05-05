/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:33:11 by minlee            #+#    #+#             */
/*   Updated: 2021/02/24 16:35:07 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int		n;
	char	tmp;

	n = 0;
	while (str[n] != '\0')
	{
		tmp = str[n];
		if (!((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')))
			return (0);
		n++;
	}
	return (1);
}