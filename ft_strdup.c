/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:56:15 by amejia            #+#    #+#             */
/*   Updated: 2023/01/17 14:02:37 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		str_len;
	char	*dest;

	str_len = ft_strlen(src);
	dest = (char *) malloc ((ft_strlen(src) + 1) * sizeof (char));
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}
