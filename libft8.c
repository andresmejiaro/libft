/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:58:55 by amejia            #+#    #+#             */
/*   Updated: 2023/01/16 23:30:31 by amejia           ###   ########.fr       */
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
	char    *s2;
	char	*next_position;
	int		length;

	n_lines = count_char (s, c) + 1;
	matrix = (char **) malloc (n_lines * sizeof (int));
	if (matrix == 0)
		return (0);
	iterator = 0;
	s2=ft_strdup(s);
	position = s2;
	while (iterator < n_lines)
	{
		if(iterator < n_lines -1)
			next_position = ft_strchr(position, c);
		else 
			next_position = ft_strchr(position, '\0');
		length = next_position - position;
		if(length == 0)
		{
			position = next_position +1;
			n_lines--;
			continue;
		}
		matrix[iterator]=(char *)malloc(length+1);
		if(matrix[iterator]==0)
			return (0);
		ft_strlcpy(matrix[iterator],position,length+1);
		position = next_position + 1;
		iterator++;
	}
	matrix[iterator] = 0;
	return (matrix);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int length_s;
	int counter;
	char *to_return;

	length_s = ft_strlen((char *)s);
	to_return = (char *)malloc(length_s+1);
	if (to_return == 0)
		return (0);
	counter = 0;
	while (counter < length_s)
	{
		to_return[counter]=(*f)(counter,s[counter]);
		counter++;	
	}
	to_return[counter]='\0';
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
