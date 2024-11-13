/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_and_parse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:28:08 by vshpilev          #+#    #+#             */
/*   Updated: 2024/09/24 12:28:15 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	if (!str || ft_strlen(str) == 0)
		return (0);
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_input(int argc, char **argv, char **numbers)
{
	int				i;
	long long int	num;

	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			if (numbers)
				free_numbers(numbers);
			error();
		}			
		num = ft_atoi_ver_2(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			if (numbers)
				free_numbers(numbers);
			error();
		}
		i++;
	}
	check_duplicates(argc, argv, numbers);
}

t_node	*create_node(int data, t_stack *stack)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack_on_error(stack);
		error();
	}
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_stack(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		error();
	stack->top = NULL;
	stack->size = 0;
	i = 0;
	while (i < argc)
	{
		add_node_to_stack(stack, create_node(ft_atoi_ver_2(argv[i]), stack));
		i++;
	}
	return (stack);
}
