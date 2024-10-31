/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ver_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:02:34 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/31 17:02:38 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
		|| c == '\f');
}

int	ft_atoi_ver_2(const char *str)
{
	char		sign;
	long long	res;
	long long	res_prev;

	sign = 1;
	res = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		res_prev = res;
		res = res * 10 + (*(str++) - '0');
		if ((res_prev ^ res) < 0
			|| (sign == 1 && res > INT_MAX)
			|| (sign == -1 && (-res) < INT_MIN))
		{
			error();
		}
	}
	return ((int)res * sign);
}
