/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:04:59 by minlee            #+#    #+#             */
/*   Updated: 2021/05/11 20:54:26 by minlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa(int n);

int     ft_atoi(const char *str);

int     ft_isprint(int c);

void    *ft_calloc(size_t count, size_t size);

void    *ft_memccpy(void *dest, const void *src, int c, size_t n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void    ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char    *ft_strtrim(char const *s1, char const *set);

char    *ft_strdup(const char *src);

size_t  ft_strlcpy(char *dest, const char *src, size_t  size);

char    **ft_split(const char *str, char charset);

char	*ft_substr(char const *s, unsigned int start, size_t len);

void    *ft_memchr(const void * ptr, int value, size_t num);

int     ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

int     ft_memcmp(const void *ptr1, const void *ptr2, size_t num);

char    *ft_strnstr(char *str, const char *to_find, size_t len);

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

size_t   ft_strlcat(char *dest,const char *src, size_t size);

int		isprint(int c);

size_t	ft_strlen(const char *str);

typedef struct	s_list
{
	void		*content;
	struct		s_list *next;
}				t_list;

t_list	*ft_lstnew(void *content);

t_list	*ft_lstlast(t_list *lst);

int     ft_lstsize(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
