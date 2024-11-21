/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:08:30 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/28 14:08:32 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_min_rotations(t_stack *stack, int target_pos)
{
	int	half_size;

	half_size = stack->size / 2;
	if (target_pos <= half_size)
		return (1);
	else
		return (0);
}

void	move_element_to_top(t_push_swap *stacks, int target_pos)
{
	if (find_min_rotations(stacks->a, target_pos))
	{
		while (target_pos > 0)
		{
			ra(stacks);
			target_pos--;
		}
	}
	else
	{
		while (target_pos < stacks->a->size)
		{
			rra(stacks);
			target_pos++;
		}
	}
}

int	find_max_digits(t_stack *stack)
{
	t_node	*current;
	int		max_value;
	int		max_digits;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max_value = current->data;
	max_digits = 0;
	while (current != NULL)
	{
		if (current->data > max_value)
			max_value = current->data;
		current = current->next;
	}
	while (max_value != 0)
	{
		max_value /= 10;
		max_digits++;
	}
	return (max_digits);
}

void	validate_input(int argc, char **argv, char **numbers);
t_stack	*parse_input(int argc, char **argv, char **numbers);

void	sort_stacks(t_push_swap *stacks)
{
	if (is_sorted(stacks->a))
	{
		free_stack(stacks->a);
		free_stack(stacks->b);
		exit(0);
	}
	if (stacks->a->size == 2)
		sort_two(stacks);
	else if (stacks->a->size == 3)
		sort_three(stacks);
	else if (stacks->a->size == 4)
		sort_four(stacks);
	else if (stacks->a->size == 5)
		sort_five(stacks);
	else
		radix_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_push_swap	stacks;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		error();
	initialize_stacks(&stacks, argc, argv);
	get_rank(&stacks);
	sort_stacks(&stacks);
	free_stack(stacks.a);
	free_stack(stacks.b);
	return (0);
}
