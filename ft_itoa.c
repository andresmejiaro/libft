/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:54:02 by amejia            #+#    #+#             */
/*   Updated: 2023/01/16 23:54:05 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int pseudolog10(int n)
{
	if (n == -2147483648)
		return(11);
	if (n < 0)
		return (1+ pseudolog10(-n));
	if (n <= 9)
		return (1);
	return (1+pseudolog10(n/10));
}


char *ft_itoa(int n)
{
	char 	*to_return;
	int		string_size;
	char	*work_head;
	int		counter;

	counter = 0;
	string_size = pseudolog10(n);
	to_return=(char *)malloc((string_size+1) * sizeof(char));
	if(to_return == 0)
		return (0);
	work_head = to_return + string_size;
	if (n == -2147483647 -1)
	{
		ft_strlcpy(to_return, "-2147483648", string_size+1);
		return(to_return);	
	}
	*work_head ='\0';
	work_head--;
	if (n < 0)
	{
		n = -n;
		*to_return = '-';
		counter++;
	}
	while (counter < string_size)
	{
		*work_head = n % 10 + '0';
		n = n / 10;
		counter ++;
		work_head--;
	}
	return (to_return);
}