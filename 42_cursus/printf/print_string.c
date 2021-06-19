#include "ft_printf.h"

char	*parse_buf(char *string, int end, int len)
{
	int		i;
	char	*buf;

	end = end < len ? end : len;
	if (!(buf = (char *)malloc(sizeof(char) * end + 1)))
		return (NULL);
	i = 0;
	while (i < end)
	{
		buf[i] = string[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int		put_width_str(char **buf, t_info *info)
{
	char	*width;
	int		i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	if ((width = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1))) == 0)
		return (0);
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		width[i] = (info->zero == 1) ? '0' : ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf);
	else
		*buf = ft_strjoin(*buf, width);
	return (info->width);
}


int		print_string(char *string, t_info *info)
{
	int		print_size;
	char	*buf;

	print_size = 0;
	if (string == NULL)
		string = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(string))
		info->prec = ft_strlen(string);
	buf = parse_buf(string, info->prec, ft_strlen(string));
	print_size = put_width_str(&buf, info);
	ft_putstr(buf);
	free(buf);
	return (print_size);
}
