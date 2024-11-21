/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:03:12 by vshpilev          #+#    #+#             */
/*   Updated: 2024/10/31 17:03:14 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_amout_bits(int num)
{
	int	i;

	i = 0;
	while (1 << i <= num)
		i++;
	return (i);
}

static void	check_bit_a(t_push_swap *stacks, int shift)
{
	int		i;
	int		moves;

	moves = stacks->a->size;
	i = 0;
	while (i < moves)
	{
		if (stacks->a->top->rank & (1 << shift))
			ra(stacks);
		else
			pb(stacks->a, stacks->b);
		i++;
	}
}

static void	check_bit_b(t_push_swap *stacks, int shift)
{
	int		i;
	int		moves;

	moves = stacks->b->size;
	i = 0;
	while (i < moves)
	{
		if (stacks->b->top->rank & (1 << shift))
			pa(stacks->a, stacks->b);
		else
			rb(stacks);
		i++;
	}
}

static void	move_num_to_a(t_push_swap *stacks)
{
	while (stacks->b->size)
		pa(stacks->a, stacks->b);
}

void	radix_sort(t_push_swap *stacks)
{
	int	shift_limit;
	int	i;

	shift_limit = max_amout_bits(stacks->a->size);
	i = 0;
	while (i < shift_limit)
	{
		check_bit_a(stacks, i);
		if (i < shift_limit - 1)
			check_bit_b(stacks, i + 1);
		else
			move_num_to_a(stacks);
		i++;
	}
}
