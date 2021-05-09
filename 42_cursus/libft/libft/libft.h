/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:04:59 by minlee            #+#    #+#             */
/*   Updated: 2021/03/08 23:10:22 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <stdlib.h>

int     is_sep(char c, char charset);

int     is_count(char *str, char charset);

void    insert(char *arr, char *str, int n, int m); 

int     ff(char **arr, char *str, char charset);

char    **ft_split(char *str, char charset);

char	*ft_substr(char const *s, unsigned int start, size_t len);

void    *ft_memchr(const void * ptr, int value, size_t num);

int     ft_strncmp(char *s1, char *s2, unsigned int n);

char	*ft_strjoin(char const *s1, char const *s2);

int     ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

char    *ft_strnstr(char *str, char *to_find, size_t len);

int     func(char *str, char *to_find, size_t len);

void    *ft_bzero(void *dest, size_t len);

void    *ft_memcpy(void *dest, const void *src, size_t n);

char    *ft_strrchr(const char *s, int c);

int     ft_isalnum(int c);

void    *ft_memmove(void *dest, const void *src, size_t n);

int     ft_tolower(int c);

int     ft_isalpha(int c);

void	*ft_memset(void * ptr, int value, size_t num);

int     ft_toupper(int c);

int     ft_isascii(int c);

char    *ft_strchr(const char* str, int c);

int		ft_isdigit(int c);

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size);

int		isprint(int c);

size_t	ft_strlen(const char *str);


#endif
