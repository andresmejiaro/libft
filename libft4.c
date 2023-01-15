/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/15 21:57:54 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int counter;

	counter = 0;
	while (counter < n)
	{
		if (*(s1+counter) != *(s2+counter) || *(s1+counter) == '\0' || *(s2+counter) == '\0')
			return (*((unsigned char *)(s1 + counter)) - *((unsigned char *)(s2 + counter)));
		counter++;
	}
	return (0);
}



static int pseudolog10(int n)
{
	if (n == -2147483648)
		return(11);
	if (n < 0)
		return (1+ pseudolog10(-n));
	if (n <= 9)
		return (1);
	return (1+pseudolog10(n/10));
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int		counter;
	unsigned int		size_src;
	
	size_src = ft_strlen(src);
	counter = 0;
	while (counter < size && counter <= size_src)
	{
		if (counter < size - 1 && counter < size_src)
			*dest = *src;
		else
			*dest = '\0';
		if (counter < size - 1)
			dest++;
		if (counter < size_src - 1)
			src++;
		counter++;
	}
	return (size_src);
}




char *ft_itoa(int n)
{
	char 	*to_return;
	int		string_size;
	char	*work_head;
	int		counter;

	counter = 0;
	string_size = pseudolog10(n);
	to_return=(char *)malloc((string_size+1) * sizeof(char));
	if(to_return == 0)
		return (0);
	work_head = to_return + string_size;
	if (n == -2147483647 -1)
	{
		ft_strlcpy(to_return, "-2147483648", string_size+1);
		return(to_return);	
	}
	*work_head ='\0';
	work_head--;
	if (n < 0)
	{
		n = -n;
		*to_return = '-';
		counter++;
	}
	while (counter < string_size)
	{
		*work_head = n % 10 + '0';
		n = n / 10;
		counter ++;
		work_head--;
	}
	return (to_return);
}



size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	unsigned int	len_dest;
	unsigned int	len_src;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	
	if(dstsize < len_dest)
	{
		return (len_src+dstsize);
	}	
	while (*dest != '\0' )
	{
		dest++;
	}
	ft_strlcpy(dest, src, dstsize - len_dest);
	return (len_src+len_dest);
}