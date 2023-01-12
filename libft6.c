/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:06:01 by amejia            #+#    #+#             */
/*   Updated: 2023/01/12 21:10:43 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, unsigned int n)
{
	unsigned int counter;

	counter = 0;
	while (*((char *)s) != '\0' && counter < n)
	{
		if (*((char *)s) == c)
			return (s);
		counter++;
		s++;
	}
	return (0);
}

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int counter;

	counter = 0;
	while (counter < n)
	{
		if (*((char *)(s1 + counter)) != *((char *)(s2 + counter)))
			return (*((char *)(s1 + counter)) - *((char *)(s2 + counter)));
		counter++;
	}
	return (0);
}

char	*ft_strnstr(char *s1, char *s2, unsigned int n)
{
	char				*s1_aux;
	char				*s2_aux;

	if (ft_strlen(s2) == 0)
		return (s1);
	while (*s1 != '\0' && n > 0)
	{
		if (*s1 == *s2)
		{
			s1_aux = s1;
			s2_aux = s2;
			while (*s1_aux == *s2_aux)
			{
				s1_aux++;
				s2_aux++;
				if (*s2_aux == '\0')
					return (s1);
				if (*s1_aux == '\0')
					return (0);
			}
		}
		s1++;
		n--;
	}
	return (0);
}

 void *ft_calloc(unsigned int count, unsigned int size)
{
	return (malloc(count * size));	
}

char	*ft_strdup(char *src)
{
	int		str_len;
	char	*dest;

	str_len = ft_strlen(src);
	dest = (char *) malloc (ft_strlen(src) * sizeof (char));
	ft_strlcpy(dest,src,ft_strlen(src));
	return (dest);
}