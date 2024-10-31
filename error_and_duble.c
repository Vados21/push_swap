/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_duble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:58:52 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/29 13:58:54 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (i < argc - 1)
	{
		num1 = ft_atoi_ver_2(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num2 = ft_atoi_ver_2(argv[j]);
			if (num1 == num2)
				error();
			j++;
		}
		i++;
	}
}
