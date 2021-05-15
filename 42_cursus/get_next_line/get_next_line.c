/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:54:16 by minlee            #+#    #+#             */
/*   Updated: 2021/05/13 20:04:20 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_lines.h"
#include <fcntl.h>
#include <stdio.h>

int get_next_line(int fd, char **line)
{
	static char	*storage;
	char		*str1;
	char		*str2;
	char		buf[BUFFER_SIZE];
	int			read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	if (read_size < 0)
		return (-1);
	else if (read_size == 0)
		return (0);
	if ((str2 = malloc(sizeof(char) * (read_size + 1))) == 0)
		return (-1);
	str2[read_size] = 0;
	while (--read_size >= 0)
		str2[read_size] = buf[read_size];
	printf("%s",str2);
	//	tmp = ft_strjoin(storage,st2);

	//	return (0);
}


int	main()
{
	int		a;
	int		fd;
	char	**line;

	fd = open("test",O_RDONLY);
	a = get_next_line(fd, line);
}
