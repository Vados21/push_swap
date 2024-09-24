/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:41:34 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/13 12:41:36 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (stack->size < 2)
		return ;

	t_node *first = stack->top;
	t_node *last = stack->top;

	while (last->next != NULL)
		last = last->next;

	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void print_stack(t_stack *stack, char *stack_name)
{
    t_node *current = stack->top;
    printf("Stack %s: ", stack_name);
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void ra(t_push_swap *stacks)
{
    write(1, "Before ra\n", 10);  // Отладочный вывод
    rotate(stacks->a);
    write(1, "ra\n", 3);
    print_stack(stacks->a, "a");  // Отладочный вывод состояния стека a
	print_stack(stacks->b, "b");
}

void	rb(t_push_swap *stacks)
{
	rotate(stacks->b);
	write(1, "rb\n", 3);
}

void	rr(t_push_swap *stacks)
{
	rotate(stacks->a);
	rotate(stacks->b);
	write(1, "rr\n", 3);
}
