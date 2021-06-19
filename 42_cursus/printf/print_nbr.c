#include "ft_printf.h"

int		put_pointer_prefix(char **buf)
{
	char    *point;

    if(!(point = (char *)malloc(sizeof(char) * 3)))
            return (0);
	point[0] = '0';
	point[1] = 'x';
	point[2] = '\0';
	*buf = ft_strjoin(point, *buf);
	return (ft_strlen(*buf));
}

int		put_minus2(int buf_len, t_info *info, char **buf)
{
	int		len_add;
	char	*minus;

	if(!(minus = (char *)malloc(sizeof(char) * 2)))
            return (0);
    minus[0] = '-';
    minus[1] = '\0';
	len_add = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			*buf = ft_strjoin(minus, *buf);
			len_add = 1;
		}
		else
		{
			*buf[0] = '-';
			free(minus);
		}
	}
	return (len_add);
}

int		put_minus(t_info *info, char **buf)
{
	int		len_add;
	char	*minus;

	if(!(minus = (char *)malloc(sizeof(char) * 2)))
			return (0);
	minus[0] = '-';
	minus[1] = '\0';
	len_add = 0;
	if ((info->type = 'i' || info->type == 'd') && 
			info->zero == 0 && info->nbr_sign == -1)
	{
		*buf = ft_strjoin(minus, *buf);
		len_add = 1;
	}
	else
		free(minus);
	return (len_add);
}


int		put_prec_str(unsigned long long nbr, t_info *info, char **buf)
{
	int		buf_len;
	int		print_size;
	int		i;

	buf_len = ft_nbrlen(nbr, info);
	print_size = (info->prec > buf_len) ? info->prec : buf_len;
	if (!(*buf = (char *)malloc(sizeof(char) * print_size + 1)))
		return (0);
	i = 0;
	(*buf)[print_size] = '\0';
	while (buf_len + i < print_size)
	{
		(*buf)[print_size] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && info->prec != 0)
		(*buf)[print_size - i] = '0';
	while (nbr)
	{
		(*buf)[print_size - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (buf_len);
}

int		print_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		print_size;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = put_prec_str(nbr, info, &buf);
	buf_len += put_minus(info, &buf);
	if (info->type == 'p')
		buf_len = put_pointer_prefix(&buf);
	print_size = put_width_str(&buf, info);
	print_size += put_minus2(buf_len, info, &buf);
	ft_putstr(buf);
	free(buf);
	return (print_size);
}
