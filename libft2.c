/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/12 20:01:33 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	return (c + 'A' - 'a');
}

int	ft_tolower(int c)
{
	return (c + 'a' - 'A');
}

void	ft_putchar_fd(char c,int fd)
{
	write(fd,&c,1);
}

void	ft_putstr_fd(char *s,int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putendl_fd(char *s,int fd)
{
	ft_putstr_fd(s,fd);
	write(fd,"\n",1);
}
