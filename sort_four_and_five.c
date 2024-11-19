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

void	find_mins(t_push_swap *stacks, long long int *min1, long long int *min2)
{
	t_node	*tmp;

	*min1 = LLONG_MAX;
	*min2 = LLONG_MAX;
	tmp = stacks->a->top;
	while (tmp)
	{
		if (tmp->data < *min1)
		{
			*min2 = *min1;
			*min1 = tmp->data;
		}
		else if (tmp->data < *min2 && tmp->data != *min1)
		{
			*min2 = tmp->data;
		}
		tmp = tmp->next;
	}
}

int	find_position(t_stack *stack, long long int value)
{
	t_node	*current;
	int		position;

	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->data == value)
			break ;
		current = current->next;
		position++;
	}
	return (position);
}

void	extract_mins(t_push_swap *stacks)
{
	long long int	min1;
	long long int	min2;
	int				pos_min1;
	int				pos_min2;

	find_mins(stacks, &min1, &min2);
	pos_min1 = find_position(stacks->a, min1);
	pos_min2 = find_position(stacks->a, min2);
	if (pos_min1 <= stacks->a->size / 2)
		while (stacks->a->top->data != min1)
			ra(stacks);
	else
		while (stacks->a->top->data != min1)
			rra(stacks);
	pb(stacks->a, stacks->b);
	pos_min2 = find_position(stacks->a, min2);
	if (pos_min2 <= stacks->a->size / 2)
		while (stacks->a->top->data != min2)
			ra(stacks);
	else
		while (stacks->a->top->data != min2)
			rra(stacks);
	pb(stacks->a, stacks->b);
	if (stacks->b->top->data < stacks->b->top->next->data)
		sb(stacks);
}

void	sort_five(t_push_swap *stacks)
{
	extract_mins(stacks);
	sort_three(stacks);
	if (stacks->b->top->data > stacks->b->top->next->data)
	{
		pa(stacks->a, stacks->b);
		pa(stacks->a, stacks->b);
	}
	else
	{
		pa(stacks->a, stacks->b);
		sa(stacks);
		pa(stacks->a, stacks->b);
	}
}

void	sort_four(t_push_swap *stacks)
{
	long long int	min1;
	long long int	min2;

	find_mins(stacks, &min1, &min2);
	while (stacks->a->top->data != min1)
		ra(stacks);
	pb(stacks->a, stacks->b);
	sort_three(stacks);
	pa(stacks->a, stacks->b);
}
