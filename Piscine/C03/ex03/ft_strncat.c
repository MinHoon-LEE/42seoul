/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:29:21 by minlee            #+#    #+#             */
/*   Updated: 2021/02/25 01:46:16 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	n;
	unsigned int	m;

	m = 0;
	n = 0;
	while (dest[n] != '\0')
	{
		n++;
	}
	while (m < nb && src[m] != '\0')
	{
		dest[n + m] = src[m];
		m++;
	}
	dest[n + m] = '\0';
	return (dest);
}
