/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:32:01 by minlee            #+#    #+#             */
/*   Updated: 2021/02/24 23:01:21 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	tmp;

	tmp = 0;
	while (tmp < n && src[tmp] != '\0')
	{
		dest[tmp] = src[tmp];
		tmp++;
	}
	while (tmp < n)
	{
		dest[tmp] = '\0';
		tmp++;
	}
	return (dest);
}
