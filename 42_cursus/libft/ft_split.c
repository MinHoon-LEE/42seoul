/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:38:14 by minlee            #+#    #+#             */
/*   Updated: 2021/05/13 15:20:54 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_count(char const *str, char charset)
{
	int		n;
	int		count;
	int		check;

	check = 0;
	count = 0;
	n = 0;
	while (str[n] != '\0')
	{
		if (str[n] != charset && check == 0)
		{
			check = 1;
			count++;
		}
		if (str[n] == charset)
			check = 0;
		n++;
	}
	return (count);
}

static int	remove(char **arr)
{
	unsigned int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static void	insert(char *arr, char const *str, int n, int m)
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

static int	ff(char **arr, char const *str, char charset, int i)
{
	int		n;
	int		m;

	n = 0;
	m = -1;
	while (str[++m] != '\0')
		if (str[m] == charset)
		{
			if (m - n > 0)
			{
				if ((arr[i] = malloc(sizeof(char) * (m - n + 1))) == 0)
					return (remove(arr));
				insert(arr[i], str, n, m);
				i++;
			}
			n = m + 1;
		}
	if (m - n > 0)
	{
		if ((arr[i] = malloc(sizeof(char) * (m - n + 1))) == 0)
			return (remove(arr));
		insert(arr[i], str, n, m);
	}
	return (1);
}

char		**ft_split(char const *str, char charset)
{
	int		count;
	char	**arr;
	int		n;

	if (str == 0)
		return (0);
	count = is_count(str, charset);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == 0)
		return (0);
	n = ff(arr, str, charset, 0);
	if (n == 0)
		return (NULL);
	arr[count] = 0;
	return (arr);
}
