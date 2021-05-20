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

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int     check_option(const char c)
{
    if (c == '%')
        return (-1);
    else if (c == 'c')
        return (0);
    else if (c == 's')
        return (1);
    else if (c == 'p')
        return (2);
    else if (c == 'd')
        return (3);
    else if (c == 'i')
        return (4);
    else if (c == 'u')
        return (5);
    else if (c == 'x')
        return (6);
    else if (c == 'X')
        return (7);
    else
        return (-2);
}

int     count_in(const char *ptr)
{
    int     n;
    int     count;

    count = 0;
    n = -1;
    while (ptr[++n])
    {
        if (ptr[n] == '%')
        {
            if (check_option(ptr[n+1]) >= 0)
            {
                n++;
                count++;
            }
            else if (check_option(ptr[n + 1] == -1))
                n++;
        }
    }
    return (count);
}

int     count_parameter(const char *arr, va_list ap)
{
    int     count;
    int     arg;

    count = 0;
    while ((arg = va_arg(ap, int)) != 0)
        count++;
    return (count);
}

int		ft_printf(const char *arr, ...)
{
	va_list	ap;
	void	**storage;
	char	arg;

	va_start(ap, arr);
	if (count_in(arr) != count_parameter(arr,ap))
		return (-1);
	va_end(ap);
	return (0);
}

int		main(void)
{
	char	a;

	a = 'c';
	ft_printf("%c, %d ,**! %% %c",a,a,a,a);
	return (0);
}
