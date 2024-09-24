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

int find_max_bits(t_stack *stack)
{
    if (stack == NULL || stack->top == NULL)
        return 0;  // Если стек пустой, нет битов

    int max_num;
    int max_bits = 0;
    t_node *current = stack->top;

    // Предполагаем, что вершина стека содержит максимальное число
    max_num = current->data;

    // Проходим по стеку и находим максимальное число
    while (current != NULL)
    {
        if (current->data > max_num)
            max_num = current->data;
        current = current->next;
    }

    // Теперь находим количество битов для максимального числа
    while (max_num >> max_bits != 0)  // Сдвигаем число вправо, пока не достигнем 0
        max_bits++;

    return max_bits;
}


void radix_sort(t_push_swap *stacks)
{
    int max_bits = find_max_bits(stacks->a);
    int size = stacks->a->size;
    int i = 0;  // Для внешнего цикла

    // Внешний цикл по битам
    while (i < max_bits)
    {
        int j = 0;  // Для внутреннего цикла

        // Внутренний цикл для прохода по элементам стека
        while (j < size)
        {
            int num = stacks->a->top->data;

            if ((num >> i) & 1)
                ra(stacks);
            else
                pb(stacks->a, stacks->b);

            j++;  // Увеличиваем счетчик
        }

        // Возвращаем все элементы из стека b в стек a
        while (stacks->b->size > 0)
            pa(stacks->a, stacks->b);

        // Проверяем, отсортирован ли стек
        if (is_sorted(stacks->a))
            break;  // Прерываем цикл, если стек отсортирован

        i++;  // Увеличиваем счетчик для внешнего цикла
    }
}



