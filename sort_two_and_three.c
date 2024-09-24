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
		stacks->a->top->data,                     // Получаем первый элемент (верхний элемент стека)
		stacks->a->top->next->data,               // Получаем второй элемент
		stacks->a->top->next->next->data);        // Получаем третий элемент
}

void	sort_two(t_push_swap *stacks)
{
	if (stacks->a->top->data > stacks->a->top->next->data)  // Проверяем два элемента в стеке
		sa(stacks);  // Если верхний элемент больше второго, меняем их местами
}
