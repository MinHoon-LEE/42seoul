/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:38:14 by minlee            #+#    #+#             */
/*   Updated: 2021/03/10 13:09:25 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int		n;

	n = 0;
	while (charset[n] != '\0')
	{
		if (c == charset[n])
			return (1);
		n++;
	}
	return (0);
}

int		is_count(char *str, char *charset)
{
	int		n;
	int		count;
	int		check;

	check = 0;
	count = 0;
	n = 0;
	while (str[n] != '\0')
	{
		if (is_sep(str[n], charset) == 0 && check == 0)
		{
			check = 1;
			count++;
		}
		if (is_sep(str[n], charset) == 1)
			check = 0;
		n++;
	}
	return (count);
}

void	insert(char *arr, char *str, int n, int m)
{
	int		a;

	a = 0;
	while (n < m)
	{
		arr[a] = str[n];
		a++;
		n++;
	}
	arr[a] = '\0';
}

void	ff(char **arr, char *str, char *charset)
{
	int		n;
	int		m;
	int		i;

	i = 0;
	n = 0;
	m = -1;
	while (str[++m] != '\0')
	{
		if (is_sep(str[m], charset) == 1)
		{
			if (m - n > 0)
			{
				arr[i] = malloc(sizeof(arr[i]) * (m - n + 1));
				insert(arr[i], str, n, m);
				i++;
			}
			n = m + 1;
		}
	}
	if (m - n > 0)
	{
		arr[i] = malloc(sizeof(arr[i]) * (m - n));
		insert(arr[i], str, n, m);
	}
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	char	**arr;

	count = is_count(str, charset);
	arr = (char **)malloc(sizeof(arr) * (count + 1));
	ff(arr, str, charset);
	arr[count] = 0;
	return (arr);
}
