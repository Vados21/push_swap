/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_and_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:46:13 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/24 11:46:15 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	find_mins(t_push_swap *stacks, int *min1, int *min2)
{
	t_node	*tmp;

	*min1 = 5;
	*min2 = 5;
	tmp = stacks->a->top;
	while (tmp)
	{
		if (tmp->data < *min1)
		{
			*min2 = *min1;
			*min1 = tmp->data;
		}
		else if (tmp->data < *min2)
		{
			*min2 = tmp->data;
		}
		tmp = tmp->next;
	}
}

void	extract_mins(t_push_swap *stacks)
{
	int		min1;
	int		min2;

	find_mins(stacks, &min1, &min2);
	while (stacks->a->top->data != min1 && stacks->a->top->data != min2)
		ra(stacks);
	pb(stacks->a, stacks->b);
	while (stacks->a->top->data != min1 && stacks->a->top->data != min2)
		ra(stacks);
	pb(stacks->a, stacks->b);
	if (stacks->b->top->data < stacks->b->top->next->data)
		rb(stacks);
}

void	sort_four(t_push_swap *stacks)
{
	int		min1;
	int		min2;

	find_mins(stacks, &min1, &min2);
	while (stacks->a->top->data != min1)
		ra(stacks);
	pb(stacks->a, stacks->b);
	sort_three(stacks);
	pa(stacks->a, stacks->b);
	print_stack(stacks->a, "a"); // debug
}

void	sort_five(t_push_swap *stacks)
{
	extract_mins(stacks);
	sort_three(stacks);
	pa(stacks->a, stacks->b);
	pa(stacks->a, stacks->b);
	print_stack(stacks->a, "a"); //debug
}
