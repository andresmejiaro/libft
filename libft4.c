/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/13 19:31:14 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int counter;

	counter = 0;
	while (counter < n)
	{
		if (*(s1+counter) != *(s2+counter))
			return (*(s1 + counter) - *(s2 + counter));
		counter++;
	}
	return (0);
}



static int pseudolog10(int n)
{
	if (n == -2147483646)
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
	work_head = to_return + string_size-1;
	if (n == -2147483646)
		ft_strlcpy(to_return, "-2147483646", string_size);	
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
	unsigned int	counter;
	unsigned int	to_return;

	len_dest = ft_strlen(dest);
	to_return = ft_strlen(dest) + ft_strlen(src);

	while (*dest != '\0' )
	{
		dest++;
	}
	counter = 0;
	while ((*src != '\0') && (counter < dstsize - len_dest - 2))
	{
		*dest = *src;
		dest++;
		src++;
		counter++;
	}
	if (counter >= 0 && dstsize > 0 && len_dest >= dstsize)
		*dest = '\0';
	return (to_return);
}