/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/15 20:40:42 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	if (c == '\n' || c == '\f' || c == '\r')
		return (1);
	if (c == '-')
		return (2);
	if (c == '+')
		return (3);
	return (0);
}

int	ft_atoi(char *str)
{
	int	cumulative_sign;
	int	cumulative_sum;
	int sign_found;

	cumulative_sign = 0;
	cumulative_sum = 0;
	sign_found = 0;
	while (check_space(*str) == 1)
		if (check_space(*str))
		str++;
	while (check_space(*str) == 2 || check_space(*str) == 3)
	{
		if (check_space(*str) == 2)
			cumulative_sign++;
		sign_found++;
		str ++;
	}
	if(sign_found > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		cumulative_sum = 10 * cumulative_sum + *str - '0';
		str++;
	}
	if (cumulative_sign % 2 == 1)
		cumulative_sum = -cumulative_sum;
	return (cumulative_sum);
}



/*int	ft_atoi(char *s)
{
	int	sign;
	int	number;

	sign = 1;
	number = 0;
	while(*s == ' ' || *s == '+' || *s == '-' )
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
}*/

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