/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_and_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:28:08 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/24 12:28:15 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_number(const char *str)
{
	int	i;

	if (!str || ft_strlen(str) == 0)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error();
		i++;
	}
	return (1);
}

static void	validate_error(char **numbers)
{
	if (numbers)
	{
		free_numbers(numbers);
		error();
	}
}

static void	validate_number(const char *arg, char **numbers)
{
	if (!is_number(arg))
		validate_error(numbers);
}

void	validate_input(int argc, char **argv, char **numbers)
{
	int				i;
	long long int	num;

	i = 0;
	while (i < argc)
	{
		validate_number(argv[i], numbers);
		num = ft_atoi_ver_2(argv[i], numbers);
		if (!num)
			validate_error(numbers);
		i++;
	}
	check_duplicates(argc, argv, numbers);
}
