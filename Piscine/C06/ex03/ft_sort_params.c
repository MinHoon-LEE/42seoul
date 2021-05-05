/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 07:21:40 by minlee            #+#    #+#             */
/*   Updated: 2021/03/07 07:24:40 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *arr)
{
	int		n;

	n = 0;
	while (arr[n] != '\0')
	{
		write(1, &arr[n], 1);
		n++;
	}
	write(1, "\n", 1);
}

void	swap(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_strcmp(char *s1, char *s2)
{
	int		n;

	n = 0;
	while (s1[n] != '\0')
	{
		if (s1[n] != s2[n])
			return (s1[n] - s2[n]);
		n++;
	}
	if (s2[n] == '\0')
		return (0);
	else
		return (-s2[n]);
}

void	sort(int argc, char **argv, int *arr)
{
	int		n;
	int		m;

	n = 1;
	while (n < argc - 1)
	{
		m = 0;
		while (m < argc - 1 - n)
		{
			if (ft_strcmp(argv[arr[1 + m]], argv[arr[1 + 1 + m]]) > 0)
				swap(&arr[1 + m], &arr[1 + m + 1]);
			m++;
		}
		n++;
	}
}

int		main(int argc, char *argv[])
{
	int		n;
	int		arr[argc];

	n = 1;
	while (n < argc)
	{
		arr[n] = n;
		n++;
	}
	n = 1;
	sort(argc, argv, arr);
	while (n < argc)
	{
		putstr(argv[arr[n]]);
		n++;
	}
}
