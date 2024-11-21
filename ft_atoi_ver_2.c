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

static void	ft_atoi_error(char **numbers)
{
	if (numbers)
		free_numbers(numbers);
	error();
}

static int	is_overflow(long long int res, long sign)
{
	return ((sign * res) < INT_MIN || (sign * res) > INT_MAX);
}

long long int	ft_atoi_ver_2(const char *str, char **numbers)
{
	long			sign;
	long long int	res;

	sign = 1;
	res = 0;
	if (!str)
		ft_atoi_error(numbers);
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*(str++) - '0');
		if (is_overflow(res, sign))
			ft_atoi_error(numbers);
	}
	return (res * sign);
}
