/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_and_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:28:08 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/24 12:28:15 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void validate_input(int argc, char **argv)
{
    int i;
    int j;

    i = 0;  // Начинаем с 0 для строки
    while (i < argc)
    {
        int num = ft_atoi(argv[i]);
        if (num <= 0 || (num == 0 && argv[i][0] != '0'))
        {
            write(1, "Error\n", 6);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    i = 0;  // Начинаем с 0 для строки
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
            {
                write(1, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}





t_stack *parse_input(int argc, char **argv)
{
    t_stack *stack;
    t_node *new_node;
    t_node *current;
    int i;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        exit(EXIT_FAILURE);
    stack->top = NULL;
    stack->size = 0;

    i = 0;
    while (i < argc)
    {
        new_node = malloc(sizeof(t_node));
        if (!new_node)
            exit(EXIT_FAILURE);
        new_node->data = ft_atoi(argv[i]);
        new_node->next = NULL;

        // Если стек пустой, новый элемент становится первым
        if (!stack->top)
            stack->top = new_node;
        else
        {
            // Ищем конец стека и добавляем новый элемент в конец
            current = stack->top;
            while (current->next)
                current = current->next;
            current->next = new_node;
        }

        stack->size++;
        //printf("Added %d to stack, current size: %d\n", new_node->data, stack->size);  // Отладка

        i++;
    }

    return stack;
}

