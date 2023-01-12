/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:36:50 by amejia            #+#    #+#             */
/*   Updated: 2023/01/12 21:09:06 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
void	ft_putchar_fd(char c,int fd);
void	ft_putstr_fd(char *s,int fd);
void	ft_putendl_fd(char *s,int fd);
int	ft_atoi(char *s);
void *ft_memset(void *s, int c, unsigned int n);
void ft_bzero(void *s, unsigned int n);
void *ft_memcpy(void *dest, const void *src, unsigned int n);
int ft_strlen(char *s);
int ft_strncmp(char *s1, char *s2, unsigned int n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char *ft_itoa(int n);
int	ft_strlcat(char *s1, char *s2, unsigned int nb);
char	*ft_strjoin(int size, char **strs, char *sep);
void	ft_putnbr_fd(int nb, int fd);
char *ft_strchr(char *s, int c);
char *ft_strrchr(char *s, int c);
void *ft_memmove(void *dst, const void *src, unsigned int len);
void	*ft_memchr(void *s, int c, unsigned int n);
char	*ft_strnstr(char *s1, char *s2, unsigned int n);
void *ft_calloc(unsigned int count, unsigned int size);
char	*ft_strdup(char *src);
char *ft_substr(char const *s, unsigned int start,unsigned int  len);
char *find_end(char *s1, char *set);
char *find_begin(char *s1, char *set);
char *ft_strtrim(char *s1, char *set);
int	count_char(char *text, char find);
char **ft_split(char *s, char c);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_striteri(char *s, void (*f)(unsigned int,char*));

#endif