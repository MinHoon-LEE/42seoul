/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:10:27 by minlee            #+#    #+#             */
/*   Updated: 2021/05/19 16:10:28 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int		tmp;

	tmp = 0;
	while (str[tmp] != '\0')
		tmp++;
	return (tmp);
}

char	*ft_strdup(const char *src)
{
	int		len;
	int		n;
	char	*arr;

	n = 0;
	len = 0;
	while (src[n] != '\0')
	{
		len++;
		n++;
	}
	if (src[n] == '\0')
		len++;
	arr = (char *)malloc(sizeof(char) * len);
	if (arr == 0)
		return (0);
	n = 0;
	while (n < len)
	{
		arr[n] = src[n];
		n++;
	}
	return (arr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	src_len;

	if (dest == 0 && src == 0)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	n = 0;
	if (size == 0)
		return (src_len);
	while (n + 1 < size && src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	m;

	m = 0;
	n = 0;
	while (dest[n] != '\0' && n < size)
		n++;
	if (n + 1 < size)
	{
		while (n + m + 1 < size && src[m] != '\0')
		{
			dest[n + m] = src[m];
			m++;
		}
		dest[n + m] = '\0';
	}
	while (src[m] != '\0')
		m++;
	if (size < n)
		return (size + m);
	else
		return (n + m);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		n;
	char		*ptr;
	size_t		s1_len;

	if (s1 == 0 && s2 == 0)
		return (0);
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(sizeof(char) * n);
	if (ptr == 0)
		return (0);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	free((char *)s1);
	ft_strlcat(ptr + s1_len, s2, ft_strlen(s2) + 1);
	return (ptr);
}
