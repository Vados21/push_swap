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

#include "push_swap.h"

void validate_input(int argc, char **argv)
{
    int i;
    int j;

    // Проверка, что все аргументы являются числами
    i = 1;
    while (i < argc)
    {
        int num = atoi(argv[i]);
        if (num == 0 && argv[i][0] != '0')  // Проверка некорректных данных
        {
            printf("Error\n");
            exit(EXIT_FAILURE);
        }
        i++;
    }

    // Проверка на дубликаты
    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (atoi(argv[i]) == atoi(argv[j]))
            {
                printf("Error\n");
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
    int i;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        exit(EXIT_FAILURE);
    stack->top = NULL;
    stack->size = 0;

    i = 1;
    while (i < argc)
    {
        new_node = malloc(sizeof(t_node));
        if (!new_node)
            exit(EXIT_FAILURE);
        new_node->data = atoi(argv[i]);  // Преобразование строки в число
        new_node->next = stack->top;     // Добавление нового узла на вершину стека
        stack->top = new_node;
        stack->size++;
        i++;
    }

    return stack;
}

