/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:28:34 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/28 14:28:36 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_max_value(t_stack *stack)
{
	t_node	*current;
	int		max_value;

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

int	calculate_max_bits(int max_value)
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

void	radix_sort(t_push_swap *stacks)
{
    int min_value = find_min_value(stacks->a);
    int max_bits = calculate_max_bits(find_max_value(stacks->a) - min_value);
    int size = stacks->a->size;
    int i = 0;

    t_node *current = stacks->a->top;
    while (current != NULL)
    {
        current->data -= min_value;
        current = current->next;
    }

    while (i < max_bits)
    {
        int j = 0;
        while (j < size)
        {
            int num = stacks->a->top->data;

            if ((num >> i) & 1)
                ra(stacks);
            else
                pb(stacks->a, stacks->b);
            j++;
        }
        
        while (stacks->b->size > 0)
            pa(stacks->a, stacks->b);
        i++;
    }
    current = stacks->a->top;
    while (current != NULL)
    {
        current->data += min_value;
        current = current->next;
    }
}

