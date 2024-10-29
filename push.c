/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:23:21 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/24 13:23:23 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	t_node	*buf;

	if (!src->top)
		return ;
	buf = src->top;
	src->top = src->top->next;
	src->size--;
	if (!dst->top)
	{
		dst->top = buf;
		dst->top->next = NULL;
	}
	else
	{
		buf->next = dst->top;
		dst->top = buf;
	}
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	push_to_stack(t_stack *stack, int num)
{
	t_node	*new_node;
	t_node	*temp;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = num;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
	}
	else
	{
		temp = stack->top;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	stack->size++;
}
