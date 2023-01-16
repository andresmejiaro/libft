/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:12:52 by amejia            #+#    #+#             */
/*   Updated: 2023/01/16 18:15:27 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	char *to_return;

	to_return = malloc(ft_strlen(s1)+ft_strlen(s2)+1);
	if(to_return == 0)
		return (0);
	ft_strlcpy(to_return,(char *)s1,-1);
	ft_strlcat(to_return,(char *)s2,-1);
	return (to_return);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	c;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb < 10)
	{
		c = '0' + nb;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

char *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
			return ((char *)s);
	return (0);
}

char *ft_strrchr(const char *s, int c)
{
	char *end;
	
	end = (char *)(s + ft_strlen(s));
	while (end >= s)
	{
		if (*end == (char)c)
			return (end);
		if (end == s)
			break;
		if(end > s)
			end--;
		
	}
	return (0);
}

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int 	counter;

	if(len == 0 || (dst == 0 && src == 0))
		return (dst);
	counter = 0;
	if(dst < src)
	{
		counter = 0;
		while (counter < len)
		{
			*((char *)(dst+counter)) = *((char*)(src+counter));
			counter++;
		}
	}
	else
	{
		counter = len-1;
		while (counter >=0)
		{
			*((char *)(dst+counter)) = *((char*)(src+counter));
			if (counter ==0)
				break;
			counter--;
		}
	}
	return (dst);
}