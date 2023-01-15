/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:06:01 by amejia            #+#    #+#             */
/*   Updated: 2023/01/16 00:35:49 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int counter;

	counter = 0;
	while (counter < n)
	{
		if (*((unsigned char*)s) == (unsigned char)c)
			return ((void *)s);
		counter++;
		s++;
	}
	return (0);
}

char	*ft_strnstr(char *s1, char *s2, unsigned int n)
{
	char				*s1_aux;
	char				*s2_aux;
	unsigned int		n2;

	if (ft_strlen(s2) == 0)
		return (s1);
	while (*s1 != '\0' && n > 0)
	{
		if (*s1 == *s2)
		{
			s1_aux = s1;
			s2_aux = s2;
			n2 = n;
			while (*s1_aux == *s2_aux && n2 > 0)
			{
				if (*(s2_aux+1) == '\0')
					return (s1);
				if (*s1_aux == '\0')
					return (0);
				s1_aux++;
				s2_aux++;
				n2--;
			}
		}
		s1++;
		n--;
	}
	return (0);
}

 void *ft_calloc(unsigned int count, unsigned int size)
{
	void *mem;
		
	mem = malloc(count * size);
	if(mem == 0){
		return(0);
	}
	ft_bzero(mem,count*size);
	return (mem);	
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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	unsigned int counter;

	counter = 0;
	while (((unsigned char *)s1)[counter] == ((unsigned char *)s2)[counter] && counter < n)
		counter++;
	if (counter == n)
		return (0);
	else
		return (((unsigned char *)s1)[counter] - ((unsigned char *)s2)[counter]);
}
