/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:04:22 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/31 17:04:26 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top || !stack->top->next)
        return 1; // Считаем пустой или одноэлементный стек отсортированным

    current = stack->top;
    while (current->next)
    {
        if (current->data > current->next->data) // Проверка на порядок возрастания
        {
            return 0; // Стек не отсортирован
        }
        current = current->next;
    }
    return 1; // Стек отсортирован
}


void	setup_stacks(t_push_swap *stacks)
{
	stacks->b = malloc(sizeof(t_stack));
	stacks->b->top = NULL;
	stacks->b->size = 0;
}

void	free_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
		free(numbers[i++]);
	free(numbers);
}

void	initialize_stacks(t_push_swap *stacks, int argc, char **argv)
{
	char	**numbers;
	int		new_argc;

	if (argc == 2)
	{
		new_argc = 0;
		numbers = ft_split(argv[1], ' ');
		while (numbers[new_argc])
			new_argc++;
		validate_input(new_argc, numbers);
		stacks->a = parse_input(new_argc, numbers);
		free_numbers(numbers);
	}
	else
	{
		validate_input(argc - 1, argv + 1);
		stacks->a = parse_input(argc - 1, argv + 1);
	}
	stacks->b = malloc(sizeof(t_stack));
	stacks->b->top = NULL;
	stacks->b->size = 0;
}
