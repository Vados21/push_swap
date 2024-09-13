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

static void rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    last = last_elem(*stack);
    *stack = first->next;
    last->next = first;
    first->next = NULL;
}

void ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}

void rr_and_refresh(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*a != cheapest && *b != cheapest->target)
        rr(a, b);
    put_index(*a);
    put_index(*b);
}
