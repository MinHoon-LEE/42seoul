/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:47:07 by minlee            #+#    #+#             */
/*   Updated: 2021/02/24 22:56:05 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check(char c)
{
	char	z;

	z = 'z';
	if (!((c >= 97 && c <= z) || (c >= 65 && c <= 90) || (c >= 48 && c <= 57)))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		status;
	int		n;
	char	c;

	status = 0;
	n = 0;
	while (str[n] != '\0')
	{
		c = str[n];
		if (status == 0 && c >= 97 && c <= 122)
		{
			str[n] -= 32;
			status = 1;
		}
		if (status == 1 && c >= 65 && c <= 90)
		{
			str[n] += 32;
		}
		if (status == 0 && c >= 48 && c <= 57)
			status = 1;
		status = check(c);
		n++;
	}
	return (str);
}
