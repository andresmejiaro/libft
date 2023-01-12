/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:14:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/12 20:16:58 by amejia           ###   ########.fr       */
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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		counter;
	unsigned int		size_src;
	unsigned int		size_dest;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	counter = 0;
	while (counter < size_dest)
	{
		if (*dest == '\0')
			break ;
		if (counter < size - 1 && counter < size_src - 1)
			*dest = *src;
		else
			*dest = '\0';
		if (counter < size_dest -1)
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

int	ft_strlcat(char *s1, char *s2, unsigned int nb)
{
	unsigned int	len_s1;
	unsigned int	counter2;
	unsigned int	to_return;

	len_s1 = ft_strlen(s1);
	to_return = ft_strlen(s1) + ft_strlen(s2);
	counter2 = 0;
	while (*s1 != '\0' )
	{
		s1++;
		counter2++;
	}
	while ((*s2 != '\0') && (counter2 < nb - 1))
	{
		*s1 = *s2;
		s1++;
		s2++;
		counter2++;
	}
	if (counter2 >= len_s1)
		*s1 = '\0';
	return (to_return);
}