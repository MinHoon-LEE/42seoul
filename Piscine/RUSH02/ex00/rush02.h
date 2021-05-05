/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 23:24:19 by minlee            #+#    #+#             */
/*   Updated: 2021/03/14 23:26:25 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int				g_value;

int				g_key;

int				g_index;

int				g_status;

int				g_max;

int				g_max_curr;

void			maxlen(char c);

char			**g_key_arr;

char			**g_value_arr;

void			create_double_array();

void			insert_buf(char *buf, int m, int n);

void			insert_buf_left(char *buf, int m, int n);

void			buf_to_array(char *buf, int size);

int				len(char *src);

int				countline(int argc, char **argv);

void			free_arr();

int				input(int argc, char **argv);

char			*number(int argc, char**argv);

int				ft_strlen(char *str);

int				ft_strncmp(char *str1, char *str2, int size);

void			ft_putstr(char *str, int *spaceflag);

int				find_index(char *str, int size);

int				check_1000(int length, char *str);

void			write_999(char *str, int *spaceflag);

void			write_1000(int length, char *str, int *spaceflag);

void			write_0(int *spaceflag);

void			write_num_sub(char *str, int length, int *spaceflag);

int				check_num(char *str);

int				write_num(char *str);

char			*ft_strcpy(char *dest, char *src);

int				ft_strcmp(char *s1, char *s2);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void			print_dict_error(void);

int				is_white_space(char ch);

int				check_atoi_and_return_index(char *str);

int				is_new_line(char ch);

int				if_only_nl_at_head(char *key);

int				trim_nl_at_head(char *key);

int				check_key_format(char *key);

int				check_all_key(char **key);

int				is_nonprintable(char ch);

int				check_any_nonprintable_at_value(char *value);

void			trim_space_at_head(char *value);

int				check_all_value(char **value);

#endif
