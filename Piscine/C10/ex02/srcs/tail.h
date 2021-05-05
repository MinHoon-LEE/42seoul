/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 01:05:54 by minlee            #+#    #+#             */
/*   Updated: 2021/03/17 15:53:01 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <stdlib.h>
# include <unistd.h>

int		g_index;

char	*g_buf;

char	g_tmp1[0];

void	ft_write(char c);

void	putstr(char *arr);

void	check_print(int *check);

void	error(int n, char *base, char *arr);

void	print(char *arr, int check, char *base);

void	ft_echo(char *num);

void	print_illegal(char *base, char *num);

void	read_func(char *buf, long long size, int m, int n);

void	tail_func(int fd, long long size, char *arr);

int		ft_atoi(char *num);

void	print_basic_tail(char *arr, char *num, char *base);

void	print_tail(char *arr, char *num, char *base, int *check);

#endif
