/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:59:17 by amejia            #+#    #+#             */
/*   Updated: 2023/02/21 00:37:52 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr_fd(char *s, int fd, unsigned int n)
{
	while (*s != '\0' && n-- > 0)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

void	ft_putunbr_fd(unsigned int nb, int fd)
{
	char	c;

	if (nb < 10)
	{
		c = '0' + nb;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
