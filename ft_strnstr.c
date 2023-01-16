/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:57:23 by amejia            #+#    #+#             */
/*   Updated: 2023/01/16 23:57:26 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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