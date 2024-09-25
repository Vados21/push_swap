/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:17:39 by vshpilev          #+#    #+#             */
/*   Updated: 2024/08/29 13:17:42 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	validate_input(int argc, char **argv);
t_stack	*parse_input(int argc, char **argv);

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	handle_args(int argc, char **argv, t_push_swap *stacks)
{
	char	**numbers;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers || !numbers[0])
			return (0);
		validate_input(argc, numbers);
		stacks->a = parse_input(argc, numbers);
		free_split(numbers);
	}
	else
	{
		validate_input(argc, argv);
		stacks->a = parse_input(argc - 1, argv + 1);
	}
	return (1);
}

void	choose_sort(t_push_swap *stacks)
{
	if (stacks->a->size == 2)
		sort_two(stacks);
	else if (stacks->a->size == 3)
		sort_three(stacks);
	else if (stacks->a->size == 4)
		sort_four(stacks);
	else if (stacks->a->size == 5)
		sort_five(stacks);
	else
		radix_sort(stacks);
}

int	main(int argc, char **argv)
{
	t_push_swap	stacks;

	if (argc < 2 || !handle_args(argc, argv, &stacks))
		return (printf("Error\n"), 1);
	stacks.b = malloc(sizeof(t_stack));
	stacks.b->top = NULL;
	stacks.b->size = 0;
	if (is_sorted(stacks.a))
		return (free_stack(stacks.a), free_stack(stacks.b), 0);
	choose_sort(&stacks);
	free_stack(stacks.a);
	free_stack(stacks.b);
	return (0);
}
