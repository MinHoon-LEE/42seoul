/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:43:05 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 00:35:24 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	is_minus(int n, long long sum)
{
	if (n % 2 == 0)
		return (sum);
	else
		return (-sum);
}

int			whitespace(unsigned char c)
{
	int		check;

	check = 0;
	if (c == ' ' || c == '\t' || c == '\n')
		check = 1;
	if (c == '\v' || c == '\f' || c == '\r')
		check = 1;
	if (check == 1)
		return (1);
	else
		return (0);
}

int			not_num(unsigned char c)
{
	int		check;

	check = 0;
	if (c >= '0' && c <= '9')
		check = 1;
	if (check == 1)
		return (1);
	else
		return (0);
}

long long	ft_atoi(char *str)
{
	int				n;
	int				minus;
	long long		sum;
	int				check;

	sum = 0;
	check = 0;
	minus = 0;
	n = 0;
	while (whitespace((unsigned char)str[n]) == 1)
		n++;
	while ((unsigned char)str[n] == '+' || (unsigned char)str[n] == '-')
	{
		if ((unsigned char)str[n] == '-')
			minus++;
		n++;
	}
	while (not_num((unsigned char)str[n]) == 1)
	{
		sum = 10 * sum + (unsigned)str[n] - '0';
		n++;
	}
	return (is_minus(minus, sum));
}
