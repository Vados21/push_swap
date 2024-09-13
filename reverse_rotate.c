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

static void rev_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *cur_list;

    if (!*stack || !(*stack)->next)
        return;
    last = last_elem(*stack);
    cur_list = *stack;
    while (cur_list != NULL)
    {
        if (cur_list->next->next == NULL)
        {
            cur_list->next = NULL;
            break;
        }
        cur_list = cur_list->next;
    }
    last->next = *stack;
    *stack = last;
}

void rra(t_stack **a)
{
    rev_rotate(a);
    ft_printf("rra\n");
}

void rrb(t_stack **b)
{
    rev_rotate(b);
    ft_printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
    ft_printf("rrr\n");
}

void rrr_and_refresh(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*a != cheapest && *b != cheapest->target)
        rrr(a, b);
    put_index(*a);
    put_index(*b);
}
