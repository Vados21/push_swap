/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:41:34 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/13 12:41:36 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = stack->top;
	if (stack->size < 2)
		return ;
	while (last->next != NULL)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	print_stack(t_stack *stack, char *stack_name)
{
	t_node	*current;

	current = stack->top;
	printf("Stack %s: ", stack_name);
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

void	ra(t_push_swap *stacks)
{
	rotate(stacks->a);
	write(1, "ra\n", 3);
}

void	rb(t_push_swap *stacks)
{
	rotate(stacks->b);
	write(1, "rb\n", 3);
}

void	rr(t_push_swap *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
	write(1, "rr\n", 3);
}
