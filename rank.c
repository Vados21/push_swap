/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:12:49 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/21 17:12:52 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rank_min(t_push_swap *stacks, int i)
{
	t_node	*min;
	t_node	*temp;

	temp = stacks->a->top;
	min = NULL;
	while (temp)
	{
		if (temp->rank == -1 && (!min || temp->data < min->data))
			min = temp;
		temp = temp->next;
	}
	min->rank = i;
}

void	get_rank(t_push_swap *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a->size)
	{
		rank_min(stacks, i);
		i++;
	}
}
