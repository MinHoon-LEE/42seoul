/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:26:07 by minlee            #+#    #+#             */
/*   Updated: 2021/03/06 20:32:23 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	m;

	m = 0;
	if (n == 0)
		return (0);
	else
	{
		while (m < n && s2[m] != '\0')
		{
			if (s1[m] != s2[m])
				return (s1[m] - s2[m]);
			m++;
		}
		if (m == n)
			return (0);
		else
			return (s1[m] - s2[m]);
	}
}
