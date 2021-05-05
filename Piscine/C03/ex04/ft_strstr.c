/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:31:59 by minlee            #+#    #+#             */
/*   Updated: 2021/02/25 04:23:52 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		func(char *str, char *to_find)
{
	int		n;
	int		m;
	int		check;

	n = 0;
	while (str[n] != '\0')
	{
		m = 0;
		if (str[n] == to_find[m])
		{
			check = 1;
			while (to_find[m] != '\0')
			{
				if (str[n + m] != to_find[m])
					check = 0;
				m++;
			}
			if (check == 1)
				break ;
		}
		n++;
	}
	return (n);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		n;

	if (*to_find == '\0')
		return (str);
	n = func(str, to_find);
	if (str[n] == '\0')
		return (0);
	return (str + n);
}
