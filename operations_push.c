/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:40:48 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/13 12:40:51 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void push(t_stack **src, t_stack **dst)
{
    t_stack *buf;

    if (!*src)
        return;
    buf = *src;
    *src = (*src)->next;
    if (!*dst)
    {
        *dst = buf;
        (*dst)->next = NULL;
    }
    else
    {
        buf->next = *dst;
        *dst = buf;
    }
}

void pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, &"pa\n",3);
}

void pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, &"pb\n",3);
}
