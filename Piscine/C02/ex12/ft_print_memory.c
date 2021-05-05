/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <minlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:06:00 by minlee            #+#    #+#             */
/*   Updated: 2021/02/24 22:57:43 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_point(long long a)
{
	int		n;
	char	tmp[16];

	n = 0;
	while (n < 16)
	{
		if (a % 16 < 10)
			tmp[15 - n] = '0' + a % 16;
		else
			tmp[15 - n] = 'a' + a % 16 - 10;
		a = a / 16;
		n++;
	}
	n = 0;
	while (n < 16)
	{
		write(1, &tmp[n], 1);
		n++;
	}
}

void	print_hex(int n)
{
	char	a;

	if (n < 10)
		a = '0' + n;
	else
		a = 'a' + n - 10;
	write(1, &a, 1);
}

void	print_digit(char *addr, int n, int size)
{
	int		d1;
	int		d2;
	int		a;
	char	c;
	int		num;

	a = 0;
	while (a < 16)
	{
		c = (unsigned char)addr[16 * n + a];
		num = c;
		d1 = num / 16;
		d2 = num % 16;
		if (16 * n + a >= size)
			write(1, "  ", 2);
		else
		{
			print_hex(d1);
			print_hex(d2);
		}
		if (a % 2 == 1)
			write(1, " ", 1);
		a++;
	}
}

void	print_word(char *addr, int n)
{
	int		m;
	char	c;

	m = 0;
	while (m < 16)
	{
		c = addr[16 * n + m];
		if (c >= 32 && c <= 126)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		if (c == '\0')
			break ;
		m++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	long long		a;
	unsigned int	n;

	n = 0;
	while (n <= size / 16)
	{
		a = (long long)&addr[16 * n];
		print_point(a);
		write(1, ": ", 2);
		print_digit(addr, n, size);
		print_word(addr, n);
		write(1, "\n", 1);
		n++;
	}
	return (addr);
}
