/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:33 by amejia            #+#    #+#             */
/*   Updated: 2023/01/12 21:20:52 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,unsigned int  len)
{
	char	*to_return;
	
	to_return = (char *)malloc((len + 1) * sizeof(char));
	if (to_return == 0)
		return (0);
	ft_strlcpy(to_return,(char *) (s + start),len);
	return (to_return);
}

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