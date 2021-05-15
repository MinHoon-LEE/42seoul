/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 19:57:54 by minlee            #+#    #+#             */
/*   Updated: 2021/05/13 20:02:03 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINES_H
# define GET_NEXT_LINES_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 32

int get_next_line(int fd, char **line);


int	do_read(int fd, char *str);

#endif
