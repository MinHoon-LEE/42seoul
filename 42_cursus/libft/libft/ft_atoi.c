/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:43:05 by minlee            #+#    #+#             */
/*   Updated: 2021/05/07 17:10:06 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long calculate(unsigned long long sum, int count, int minus)
{
	if (count >= 20)
	{
		if (minus == - 1)
			return (0);
		else
			return (-1);
	}
	else
	{
		if (sum == 9223372036854775808ULL && minus == -1)
			return (long long)(-(long long)(sum));
		else if (sum > 9223372036854775807ULL)
		{
			if (minus == -1)
				return (0);
			else
				return (-1);
		}
		else
			return (minus * (long long)sum);
	}
}

int		whitespace(unsigned char c)
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

int		not_num(unsigned char c)
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

int		ft_atoi(unsigned char *str)
{
	int					n;
	int					minus;
	unsigned long long	sum;
	int					count;

	count = 0;
	sum = 0;
	minus = 1;
	n = 0;
	while (whitespace((unsigned char)str[n]) == 1)
		n++;
	if ((unsigned char)str[n] == '+' || (unsigned char)str[n] == '-')
	{
		if ((unsigned char)str[n] == '-')
			minus = -1;
		n++;
	}
	while (not_num((unsigned char)str[n]) == 1)
	{
		sum = 10UL * sum + (unsigned long long)((unsigned)str[n] - '0');
		n++;
		count++;
	}
	return (int)(calculate(sum,count,minus));
}
