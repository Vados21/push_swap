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

void push(t_stack *src, t_stack *dst)
{
    t_node *buf;

    if (!src->top)
        return;
    
    // Забираем верхний элемент из src
    buf = src->top;
    src->top = src->top->next;
    src->size--;  // Уменьшаем размер стека src

    // Добавляем элемент в dst
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
    dst->size++;  // Увеличиваем размер стека dst
}

void pa(t_stack *a, t_stack *b)
{
    push(b, a);
    write(1, "pa\n", 3);

    // Отладочные сообщения
    printf("After pa:\n");
    print_stack(a, "Stack a");  // Вывод содержимого стека a
    print_stack(b, "Stack b");  // Вывод содержимого стека b
}

void pb(t_stack *a, t_stack *b)
{
    push(a, b);
    write(1, "pb\n", 3);
}

