/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:58:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/12 21:20:13 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_char(char *text, char find)
{
	int	counter;

	counter = 0;
	while (*text != '\0')
	{
		if (*text == find)
			counter++;
		text++;
	}
	return (counter);
}

char **ft_split(char *s, char c)
{
	char    **matrix;
	int		n_lines;
	int		iterator;
	char	*position;

	n_lines = count_char (s, '\n') + 1;
	matrix = (char **) malloc (n_lines * sizeof (int));
	*matrix = ft_strdup(s);
	iterator = 1;
	position = s;
	while (iterator < n_lines)
	{
		position = ft_strnstr(position, &c,ft_strlen(position));
		*position = '\0';
		position++;
		matrix[iterator] = position;
		iterator++;
	}
	return (matrix);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int length_s;
	int counter;
	char *to_return;

	length_s = ft_strlen((char *)s);
	to_return = (char *)malloc(length_s);
	counter = 0;
	while (counter < length_s)
	{
		to_return[counter]=(*f)(counter,s[counter]);
		counter++;	
	}
	return (to_return);
}

void ft_striteri(char *s, void (*f)(unsigned int,char*))
{
	int length_s;
	int counter;
	char *to_return;

	length_s = ft_strlen(s);
	to_return = (char *)malloc(length_s);
	counter = 0;
	while (counter < length_s)
	{
		(*f)(counter, s + counter);
		counter++;	
	}
}
