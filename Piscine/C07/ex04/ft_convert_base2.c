/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:24:52 by minlee            #+#    #+#             */
/*   Updated: 2021/03/08 17:56:27 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		overlap(char *base)
{
	int		n;
	int		m;

	n = 0;
	while (base[n] != '\0')
	{
		m = 0;
		while (base[m] != '\0')
		{
			if (n != m)
			{
				if (base[n] == base[m])
					return (1);
			}
			m++;
		}
		n++;
	}
	return (0);
}

int		check_valid(char *base)
{
	int		n;
	int		check;

	n = 0;
	check = 0;
	while (base[n] != '\0')
	{
		if (base[n] == '-' || base[n] == '+')
			check = 1;
		if (base[n] == ' ' || base[n] == '\t' || base[n] == '\n')
			check = 1;
		if (base[n] == '\v' || base[n] == '\f' || base[n] == '\r')
			check = 1;
		n++;
	}
	if (overlap(base) == 1)
		check = 1;
	if (n == 0 || n == 1)
		check = 1;
	if (check == 1)
		return (1);
	return (0);
}

int		print(char c, char *base)
{
	int		n;

	n = 0;
	if (c == '-' || c == '+')
		return (-2);
	if (c == ' ' || c == '\t' || c == '\n')
		return (-3);
	if (c == '\v' || c == '\f' || c == '\r')
		return (-3);
	while (base[n] != '\0')
	{
		if (c == base[n])
			break ;
		n++;
	}
	if (base[n] == '\0')
		return (-1);
	return (n);
}

int		print1(char *str, char *base, int ba)
{
	int		n;
	int		sum;
	int		minus;

	minus = 0;
	sum = 0;
	n = 0;
	while (print(str[n], base) == -3)
		n++;
	while (print(str[n], base) == -2)
	{
		if (str[n] == '-')
			minus++;
		n++;
	}
	while (print(str[n], base) >= 0)
	{
		sum = sum * ba + print(str[n], base);
		n++;
	}
	if (minus % 2 == 1)
		sum = -sum;
	return (sum);
}

int		ft_atoi_base(char *str, char *base)
{
	int		ba;
	int		sum;
	int		minus;

	minus = 0;
	sum = 0;
	ba = 0;
	if (check_valid(base) == 0)
	{
		while (base[ba] != '\0')
			ba++;
		return (print1(str, base, ba));
	}
	return (sum);
}
