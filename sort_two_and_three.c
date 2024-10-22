/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_and_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:46:02 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/24 11:46:04 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	three_nice(t_push_swap *stacks, int first, int second, int third)
{
	if (first > second)
	{
		if (second > third)
		{
			sa(stacks);
			rra(stacks);
		}
		else
		{
			if (first > third)
				ra(stacks);
			else
				sa(stacks);
		}
	}
	else if (second > third)
	{
		if (first > third)
			rra(stacks);
		else
		{
			sa(stacks);
			ra(stacks);
		}
	}
}

void	sort_three(t_push_swap *stacks)
{
	three_nice(stacks,
		stacks->a->top->data,
		stacks->a->top->next->data,
		stacks->a->top->next->next->data);
	print_stack(stacks->a, "a");
}

void sort_two(t_push_swap *stacks)
{
    printf("sort_two called\n");  // Отладка

    // Проверяем, что два элемента в стеке действительно нужно поменять местами
    if (stacks->a->top->data > stacks->a->top->next->data)
    {
        //printf("Swapping %d and %d\n", stacks->a->top->data, stacks->a->top->next->data);  // Отладка
        sa(stacks);  // Меняем местами элементы
    }

    // Вывод содержимого стека после операции
    print_stack(stacks->a, "a");
}

