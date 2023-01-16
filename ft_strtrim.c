/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:57:38 by amejia            #+#    #+#             */
/*   Updated: 2023/01/16 23:57:41 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delete_char(char *str)
{
	while (*str != '\0')
	{
		*str = *(str + 1);
		str++;
	}
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *end;
	char *s2;

	s2 =ft_strdup((char*)s1);
	if(s2 == 0)
		return (0);
	while(ft_strchr(set,(int)(*s2)) && *s2 != '\0')
	{
		ft_delete_char(s2);
	}
	if(ft_strlen(s2)==0)
		return (s2);
	end=s2+ft_strlen(s2)-1;
	while(ft_strchr(set,(int)(*end)) && ft_strlen(s2) > 0)
	{
		ft_delete_char(end);
		end--;
	}
    
	
	return (s2);
}