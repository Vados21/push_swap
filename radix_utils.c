/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:50:14 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/30 16:50:18 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long long int	find_max_value(t_stack *stack)
{
	t_node			*current;
	long long int	max_value;

	current = stack->top;
	max_value = current->data;
	while (current != NULL)
	{
		if (current->data > max_value)
			max_value = current->data;
		current = current->next;
	}
	return (max_value);
}

long long int	calculate_max_bits(long long int max_value)
{
	int	bits;

	bits = 0;
	while (max_value > 0)
	{
		max_value /= 2;
		bits++;
	}
	return (bits);
}

int	find_min_value(t_stack *stack)
{
	t_node	*current;
	int		min_value;

	current = stack->top;
	min_value = current->data;
	while (current != NULL)
	{
		if (current->data < min_value)
			min_value = current->data;
		current = current->next;
	}
	return (min_value);
}

void	normalize_values(t_stack *stack, long long int min_value)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		current->data -= min_value;
		current = current->next;
	}
}

void	restore_values(t_stack *stack, int min_value)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		current->data += min_value;
		current = current->next;
	}
}
