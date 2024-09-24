/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:42:02 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/13 12:42:04 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	t_node *first = stack->top;
	t_node *second = stack->top->next;

	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_push_swap *stacks)
{
	swap(stacks->a);
	write(1, "sa\n", 3);
}

void	sb(t_push_swap *stacks)
{
	swap(stacks->b);
	write(1, "sb\n", 3);
}

void	ss(t_push_swap *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	write(1, "ss\n", 3);
}