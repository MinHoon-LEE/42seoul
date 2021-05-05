/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:52:43 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 03:52:54 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_memset(char *buf)
{
	int		n;

	n = 0;
	while (n < 100)
	{
		buf[n] = '\0';
		n++;
	}
}

int		main(int argc, char **argv)
{
	int		n;
	int		fd;
	char	buf[100];

	ft_memset(buf);
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			write(1, "Cannot read file.\n", 18);
		else
		{
			while ((n = read(fd, buf, sizeof(buf))) > 0)
				write(1, buf, n);
			close(fd);
		}
		return (0);
	}
}
