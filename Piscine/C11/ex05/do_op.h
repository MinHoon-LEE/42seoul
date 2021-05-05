/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 00:33:41 by minlee            #+#    #+#             */
/*   Updated: 2021/03/15 00:49:12 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void		putnbr(long long nb);

long long	ft_atoi(char *str);

void		operation(long long x1, long long x2, unsigned char c);

void		do_plus(long long x1, long long x2);

void		do_minus(long long x1, long long x2);

void		do_multi(long long x1, long long x2);

void		do_div(long long x1, long long x2);

void		do_mod(long long x1, long long x2);
#endif
