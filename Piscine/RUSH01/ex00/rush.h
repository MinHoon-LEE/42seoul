/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geokim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 14:00:20 by geokim            #+#    #+#             */
/*   Updated: 2021/03/06 23:40:37 by geokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

int		g_size;

void	ft_putchar(char c);

int		ft_error(void);

void	ft_display(int **arr);

int		**ft_create_board();

int		ft_get_size(char *str);

int		ft_is_space(char *str);

int		ft_check_valid(char *str);

int		quater(char *str);

void	ft_remove_space(char *str);

int		ft_calculate(int **arr, char *str, int x, int y);

int		ft_recursive(int **arr, char *str, int x, int y);

int		ft_check_num(int **arr, int i, int x, int y);

int		ft_check_direction(int **arr, char *str);

int		ft_check_cols_up(int **arr, char *str, int x);

int		ft_check_cols_down(int **arr, char *str, int x);

int		ft_check_rows_left(int **arr, char *str, int y);

int		ft_check_rows_right(int **arr, char *str, int y);

#endif
