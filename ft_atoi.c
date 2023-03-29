/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:50:38 by amejia            #+#    #+#             */
/*   Updated: 2023/03/29 21:59:02 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	if (c == '\n' || c == '\f' || c == '\r')
		return (1);
	if (c == '-')
		return (2);
	if (c == '+')
		return (3);
	return (0);
}

void	sign_space_control(char **str, int	*cumulative_sign, int	*sign_found)
{
	while (check_space(**str) == 1)
		if (check_space(**str))
		(*str)++;
	while (check_space(**str) == 2 || check_space(**str) == 3)
	{
		if (check_space(**str) == 2)
			(*cumulative_sign)++;
		(*sign_found)++;
		(*str)++;
	}
}

int	ft_atoi(char *str)
{
	int	cumulative_sign;
	int	cumulative_sum;
	int	sign_found;

	cumulative_sign = 0;
	cumulative_sum = 0;
	sign_found = 0;
	sign_space_control(&str, &cumulative_sign, &sign_found);
	if (sign_found > 1)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		cumulative_sum = 10 * cumulative_sum + *str - '0';
		str++;
	}
	if (cumulative_sign % 2 == 1)
		cumulative_sum = -cumulative_sum;
	return (cumulative_sum);
}

float	ft_atof(char *str)
{
	char				*dot;
	int					num[2];
	unsigned int		ct;
	float				p10;

	dot = ft_strchr(str, '.');
	if (dot == 0)
		return ((float)ft_atoi(str));
	num[0] = ft_atoi(str);
	num[1] = ft_atoi(dot +1);
	ct = 0;
	p10 = 1;
	while (ct++ < ft_strlen(dot +1))
		p10 /= 10;
	if (num[0] < 0)
		num[1] *= -1;
	return (num[0] + num[1] * p10);
}
