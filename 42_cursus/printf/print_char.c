#include "ft_printf.h"

int		print_char(int c, t_info *info)
{
	int		print_size;

	print_size = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		print_size += ft_putchar(c);
	print_size += put_width(info->width, 1, info->zero);
	if (info->minus == 0)
		print_size += ft_putchar(c);
	return (print_size);
}


int		put_width(int width, int len, int zero)
{
	int		print_size;

	print_size = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		print_size++;
	}
	return (print_size);
}
