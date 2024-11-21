/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:30:45 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/20 13:30:48 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data, t_stack *stack)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack_on_error(stack);
		error();
	}
	new_node->data = data;
	new_node->rank = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_stack(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!new_node)
	{
		free_stack_on_error(stack);
		error();
	}
	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

t_stack	*parse_input(int argc, char **argv, char **numbers)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		free_numbers(numbers);
		error();
	}
	stack->top = NULL;
	stack->size = 0;
	i = 0;
	while (i < argc)
	{
		add_node_to_stack(stack,
			create_node(ft_atoi_ver_2(argv[i], numbers), stack));
		i++;
	}
	return (stack);
}
