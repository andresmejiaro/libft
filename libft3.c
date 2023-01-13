/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/13 18:17:23 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *s)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while(*s == ' ' || *s == '+' || *s == '-')
	{
		if (*s == '-')
		{
			sign =sign * -1;
			s++;
		}
	s++;
	} 
	while (*s != '\0' && *s <= '9' && *s >= '0')
	{
		number = 10*number + *s - '0';
		s++;
	}
	return sign * 	number;
}

void *ft_memset(void *s, int c, size_t n)
{
	unsigned int		counter;
	void				*to_return;

	to_return = s;
	counter = 0;
	while (counter < n)
	{
		*((unsigned char *)s) = c;
		s++;
		counter++;
	}
	return (to_return);
}

void ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	void            *to_return;
	unsigned int    counter;
	
	if(dest == 0 && src ==0)
	{
		return 0;	
	}
		to_return = dest;
	counter = 0;
	while (counter < n)
	{
		*((char *)(dest + counter)) = *((char *)(src + counter));
		counter++;
	}

	return to_return;
}

int ft_strlen(const char *s)
{
	int counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		counter++;
	}
	return counter;
}