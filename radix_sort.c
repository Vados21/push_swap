/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:28:34 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/28 14:28:36 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	perform_bit_shift(t_push_swap *stacks, int bit)
{
	int	j;
	int	size;
	int	num;

	j = 0;
	size = stacks->a->size;
	while (j < size)
	{
		num = stacks->a->top->data;
		if ((num >> bit) & 1)
			ra(stacks);
		else
			pb(stacks->a, stacks->b);
		j++;
	}
	while (stacks->b->size > 0)
		pa(stacks->a, stacks->b);
}

void	radix_sort(t_push_swap *stacks)
{
	int	min_value;
	int	max_bits;
	int	i;

	min_value = find_min_value(stacks->a);
	normalize_values(stacks->a, min_value);
	max_bits = calculate_max_bits(find_max_value(stacks->a) - min_value);
	i = 0;
	while (i < max_bits)
	{
		perform_bit_shift(stacks, i);
		i++;
	}
	restore_values(stacks->a, min_value);
}
