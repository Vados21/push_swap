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
static void swap(t_stack **stack)
{
    int buf_n;
    int buf_index;

    if (!*stack || !(*stack)->next)
        return;
    buf_n = (*stack)->n;
    buf_index = (*stack)->index;
    (*stack)->n = ((*stack)->next)->n;
    (*stack)->index = ((*stack)->next)->index;
    ((*stack)->next)->n = buf_n;
    ((*stack)->next)->index = buf_index;
}

void sa(t_stack **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_stack **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
