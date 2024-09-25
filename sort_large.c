/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:57:05 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/24 11:57:07 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_max_digits(t_stack *stack)
{
	t_node	*current;
	int		max_value;
	int		max_digits;

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

void	radix_sort(t_push_swap *stacks)
{
	int	max_digits ;
	int	size;
	int	digit_place;
	int	j;
	int num;

	max_digits = find_max_digits(stacks->a);
	size = stacks->a->size;
	digit_place = 1;
	j = 0;
	num = stacks->a->top->data;
	while (max_digits--)
	{
		while (j < size)
		{
			if ((num / digit_place) % 10 < 5)
				pb(stacks->a, stacks->b);
			else
				ra(stacks);
			j++;
		}
		while (stacks->b->size > 0)
			pa(stacks->a, stacks->b);
		digit_place *= 10;
	}
}
