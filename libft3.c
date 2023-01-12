/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/12 20:16:40 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *s)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	} 
	while (*s != '\0' && *s <= '9' && *s >= '0')
	{
		number = 10*number + *s - '0';
		s++;
	}
	return number;
}

void *ft_memset(void *s, int c, unsigned int n)
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

void ft_bzero(void *s, unsigned int n)
{
	ft_memset(s, 0, n);
}

void *ft_memcpy(void *dest, const void *src, unsigned int n)
{
	void            *to_return;
	unsigned int    counter;

	to_return = dest;
	counter = 0;
	while (counter < n)
	{
		*((char *)(dest + counter)) = *((char *)(src + counter));
		counter++;
	}

	return to_return;
}

int ft_strlen(char *s)
{
	int counter;

	counter = 0;
	while (*(s + counter) != '\0')
	{
		counter++;
	}
	return counter;
}