/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:52:47 by amejia            #+#    #+#             */
/*   Updated: 2023/01/18 18:50:59 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == 0)
		return (0);
	ft_bzero(mem, count * size);
	return (mem);
}

/*
void	*ft_calloc(unsigned long count, unsigned long size)
{
	void *a;
	
	a=calloc(count,size);
	return (a);
}
*/