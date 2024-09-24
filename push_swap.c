/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:17:39 by vshpilev          #+#    #+#             */
/*   Updated: 2024/08/29 13:17:42 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"


//RADIX SORT

#include <stdlib.h>
#include <stdio.h>
int is_sorted(t_stack *stack)
{
    t_node *current = stack->top;

    while (current && current->next)
    {
        if (current->data > current->next->data)
            return 0;  // Не отсортировано
        current = current->next;
    }
    return 1;  // Отсортировано
}


// Прототипы вспомогательных функций
void    validate_input(int argc, char **argv);
t_stack *parse_input(int argc, char **argv);

int main(int argc, char **argv)
{
    t_push_swap stacks;

    // Проверка валидности входных данных
    if (argc < 2)
    {
        fprintf(stderr, "Error\n");
        return (1);
    }
    validate_input(argc, argv);

    // Разбираем данные и создаем стек a
    stacks.a = parse_input(argc, argv);
    stacks.b = malloc(sizeof(t_stack));
    stacks.b->top = NULL;
    stacks.b->size = 0;

        // Проверяем, отсортирован ли стек перед началом сортировки
    if (is_sorted(stacks.a))
    {
        free(stacks.a);
        free(stacks.b);
        return (0);  // Если стек отсортирован, программа завершает работу
    }

    // В зависимости от количества элементов выбираем метод сортировки
    if (stacks.a->size == 2)
        sort_two(&stacks);
    else if (stacks.a->size == 3)
        sort_three(&stacks);
    else if (stacks.a->size == 4)
        sort_four(&stacks);
    else if (stacks.a->size == 5)
        sort_five(&stacks);
    else
        radix_sort(&stacks);  // Radix сортировка для большого количества элементов

    // Очистка памяти
    free(stacks.a);
    free(stacks.b);

    return (0);
}
