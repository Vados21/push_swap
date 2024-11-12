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

void	check_duplicates(int argc, char **argv, char **numbers)
{
	int	i;
	int	j;
	long long int	num1;
	long long int	num2;

	i = 0;
	while (i < argc - 1)
	{
		num1 = ft_atoi_ver_2(argv[i]);
		while (j < argc)
		{
			num2 = ft_atoi_ver_2(argv[j]);
			if (num1 == num2)
			{
				if (numbers)
					free_numbers(numbers);
				error();
			}
			j++;
		}
		i++;
	}
}

void	free_stack_on_error(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
	free(stack);
}
