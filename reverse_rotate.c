/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:41:21 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/13 12:41:23 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack || stack->size < 2)
		return ;
	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_push_swap *stacks)
{
	reverse_rotate(stacks->a);
	write(1, "rra\n", 4);
}

void	rrb(t_push_swap *stacks)
{
	reverse_rotate(stacks->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_push_swap *stacks)
{
	reverse_rotate(stacks->a);
	reverse_rotate(stacks->b);
	write(1, "rrr\n", 4);
}
