/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:04:22 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/31 17:04:26 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

void	setup_stacks(t_push_swap *stacks)
{
	stacks->b = malloc(sizeof(t_stack));
	if (!stacks->b)
	{
		free_stack_on_error(stacks->a);
		free_stack_on_error(stacks->b);
		error();
	}
	stacks->b->top = NULL;
	stacks->b->size = 0;
}

void	initialize_stacks(t_push_swap *stacks, int argc, char **argv)
{
	char	**numbers;
	int		new_argc;

	numbers = NULL;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
		{
			free_numbers(numbers);
			error();
		}
		new_argc = count_numbers(numbers);
		validate_input(new_argc, numbers, numbers);
		stacks->a = parse_input(new_argc, numbers, numbers);
		free_numbers(numbers);
	}
	else
	{
		validate_input(argc - 1, argv + 1, NULL);
		stacks->a = parse_input(argc - 1, argv + 1, numbers);
		free_numbers(numbers);
	}
	initialize_stack_b(stacks);
}

int	count_numbers(char **numbers)
{
	int	count;

	count = 0;
	while (numbers[count])
		count++;
	return (count);
}

void	initialize_stack_b(t_push_swap *stacks)
{
	stacks->b = malloc(sizeof(t_stack));
	if (!stacks->b)
	{
		free_stack_on_error(stacks->a);
		error();
	}
	stacks->b->top = NULL;
	stacks->b->size = 0;
}
