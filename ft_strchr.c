/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:56:07 by amejia            #+#    #+#             */
/*   Updated: 2023/03/13 19:07:31 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strchr_esc(const char *s, int c)
{
	char	*org;

	org = (char *)s;
	while (*s != '\0')
	{
		if (*s == (char)c && !((s - org) > 2 && \
			(*(s - 1)) == '\\' && (*(s - 2)) == '\\'))
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
