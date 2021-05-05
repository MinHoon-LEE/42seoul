/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 23:42:02 by minlee            #+#    #+#             */
/*   Updated: 2021/03/16 00:36:05 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_H
# define HEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

int		g_index;

int		g_error_flag;

int		g_flag;

char	g_tmp[16];

char	g_pre_tmp[16];

void	print_num();

void	print_word();

int		g_tmp_index;

void	error(int n, char *base, char *arr);

void	echo_func(char *arr);

void	echo_func_c(char *arr);

void	print_word_c(char *arr);

void	print_c(char *arr);

void	print_num(int tmp, int i);

void	print_extra_num(int tmp, int i);

void	p256(int n);

void	print_word(char *arr);

void	do_hex_echo(void);

void	do_hex_echo_c(void);

void	do_hex(int argc, char **argv, char *base, int index);

void	input(int argc, char **argv, char *base);

void	putstr(char *arr);

void	hex(char *buf, int n);

void	print_hex(char *arr, int i);

void	hex_c(char *buf, int n);

void	do_hex_c(int argc, char **argv, char *base, int index);

void	print_hex_c(char *arr, int i);

void	print_c_hex(char *buf, int i);

int		cmp(char *a, char *b);

void	do_hex_echo_sub(char c);

void	do_hex_echo_c_sub(char c);

void	do_hex_sub(char c);

void	do_hex_c_sub(char c);

void	sub(void);

void	sub2(void);
#endif
