/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:19:51 by minlee            #+#    #+#             */
/*   Updated: 2021/05/20 21:08:34 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(va_list ap, t_info *info)
{
	int		print_size;
	char	type;

	print_size = 0;
	type = info->type;
	if (type == 'c')
		print_size = print_char(va_arg(ap, int), info);
	else if (type == '%')
		print_size = print_char('%', info);
	else if (type == 's')
		print_size = print_string(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		print_size = print_nbr(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		print_size = print_nbr(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		print_size = print_nbr(va_arg(ap, unsigned long long), info);
	return (print_size);
}

void	check_width_and_prc(va_list ap, char *string, t_info *info, int i)
{
	if (ft_isdigit(string[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + string[i] - 48;
		else
			info->prec = info->prec * 10 + string[i] - 48;
	}
	else if (string[i] == '*')
	{
		if (info->prec == -1)
			info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->minus = 1;
			info->width *= -1;
		}
		else
			info->prec = va_arg(ap, int);
	}
}

void	check_info(va_list ap, char *string, t_info *info, int i)
{
	if (string[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (string[i] == '-')
		info->minus = 1;
	else if (string[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(string[i]) || string[i] == '*')
		check_width_and_prec(ap, string, info, i);
}


int		do_print(va_list ap, char *string)
{
	int		i;
	int		print_size;
	t_info	*info;

	i = 0;
	print_size = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	while (string[i])
	{
		while(string[i] != '%' && string[i])
			print_size += ft_putchar(string[i++]);
		if (string[i] == '%')
		{
			start_info(info);
			while (string[++i] && !(ft_strchr(TYPE, string[i])))
				check_info(ap, string, info, i);
			info->type = string[i++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			print_size += print_type(ap, info);
		}
	}
	free(info);
	return (print_size);
}




int		ft_printf(const char *string, ...)
{
	int			print_size;
	va_list		ap;

	va_start(ap, string);
	print_size = do_print(ap, (char *)string);
	va_end(ap);
	return (print_size);
}
