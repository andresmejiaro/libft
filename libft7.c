/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:33 by amejia            #+#    #+#             */
/*   Updated: 2023/01/16 18:55:39 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,unsigned int  len)
{
	char	*to_return;
	
	to_return = (char *)malloc((len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	if(start > ft_strlen(s))
		ft_strlcpy(to_return,"",0);
	else
		ft_strlcpy(to_return,(char *) (s + start),len+1);
	return (to_return);
}
/*
char *find_end(char *s1, char *set)
{
	int		len_s1;
	int		len_set;
	int		times;
	char	*ptr;

    len_s1 = ft_strlen(s1);
	len_set = ft_strlen(set);
    times = 0;
	ptr = s1-len_set * (times + 1) + len_s1;
	while (ft_strnstr(ptr, set, len_set) == ptr)
        times++;
	return (s1 - len_set * times + len_s1);
}

char *find_begin(char *s1, char *set)
{
	int		len_s1;
	int		len_set;
	int		times;
	char	*ptr;

	len_s1 = ft_strlen(s1);
	len_set = ft_strlen(set);
    times=0;
	ptr = s1+len_set * (times);
	while (ft_strnstr(ptr, set, len_set) == ptr)
        times++;
	return (s1 + len_set * times);
}

char *ft_strtrim(char *s1, char *set)
{
	char	*begin;
	char	*end;
	int		size;

    begin = find_begin(s1, set);
    end = find_end(s1, set);
	size = end - begin;
    end=ft_substr(begin, 0, size);
	return end;
}
*/

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