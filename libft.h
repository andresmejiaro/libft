/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:36:50 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 20:53:56 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  (10)
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_itoa(int n);
size_t	ft_strlcat(char *s1, char *s2, size_t nb);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putnbr_fd(int nb, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strchr_esc(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(char *s1, char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *string, ...);
void	ft_value_swap_l(long *a, long *b);
void	ft_value_swap_i(int *a, int *b);
int		pseudolog10(int n);
int		pseudolog10_u(unsigned int n);
int		pseudologbase(long n, long base);
int		pseudologbase_u(unsigned long n, long base);
char	*get_next_line(int fd);
int		ft_abs(int x);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	ft_free_split(char **split);
char	**ft_split_esc(char *s, char c);
void	ft_delete_char(char *str);
char	*ft_min_str(char *s1, char *s2);
float	ft_atof(char *str);

#endif
