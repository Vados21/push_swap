/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:17:46 by vshpilev          #+#    #+#             */
/*   Updated: 2024/08/29 13:17:50 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

// structs
typedef struct s_node
{
	long long int	data;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node			*top;
	long long int	size;
}				t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		operation_count;
}				t_push_swap;

// operations with stacks
void			sa(t_push_swap *stacks);
void			sb(t_push_swap *stacks);
void			ss(t_push_swap *stacks);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_push_swap *stacks);
void			rb(t_push_swap *stacks);
void			rr(t_push_swap *stacks);
void			rra(t_push_swap *stacks);
void			rrb(t_push_swap *stacks);
void			rrr(t_push_swap *stacks);

// main functions
void			sort_two(t_push_swap *stacks);
void			sort_three(t_push_swap *stacks);
void			sort_four(t_push_swap *stacks);
void			sort_five(t_push_swap *stacks);
void			radix_sort(t_push_swap *stacks);

// utils for sort
void			push(t_stack *src, t_stack *dst);
void			reverse_rotate(t_stack *stack);
void			rotate(t_stack *stack);
void			swap(t_stack *stack);
void			sort_stacks(t_push_swap *stacks);
void			initialize_stacks(t_push_swap *stacks, int argc, char **argv);

// additional utils
void			validate_input(int argc, char **argv, char **numbers);
void			check_duplicates(int argc, char **argv, char **numbers);
void			error(void);
void			free_stack_on_error(t_stack *stack);
int				is_sorted(t_stack *stack);
int				is_number(char *str);

// parsing and stack functions
t_stack			*parse_input(int argc, char **argv);
void			free_stack(t_stack *stack);
void			add_node_to_stack(t_stack *stack, t_node *new_node);
void			push_to_stack(t_stack *stack, int num);
void			free_numbers(char **numbers);
void			initialize_stack_b(t_push_swap *stacks);
int				count_numbers(char **numbers);

// utils to find values

int				find_min_value(t_stack *stack);
void			normalize_values(t_stack *stack, long long int min_value);
void			restore_values(t_stack *stack, int min_value);
long long int	ft_atoi_ver_2(const char *str);
long long int	find_max_value(t_stack *stack);
long long int	calculate_max_bits(long long int max_value);
#endif
