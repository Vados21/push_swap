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
	int				data;
	int				rank;
	struct s_node	*next;
}	t_node;

// 
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
}	t_push_swap;

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
int				is_number(const char *str);

// parsing and stack functions
t_stack			*parse_input(int argc, char **argv, char **numbers);
void			free_stack(t_stack *stack);
void			add_node_to_stack(t_stack *stack, t_node *new_node);
void			push_to_stack(t_stack *stack, int num);
void			free_numbers(char **numbers);
void			initialize_stack_b(t_push_swap *stacks, char **numbers);
int				count_numbers(char **numbers);

// utils to find values
long long int	ft_atoi_ver_2(const char *str, char **numbers);
void			get_rank(t_push_swap *stacks);
void			rank_min(t_push_swap *stacks, int i);
void			get_rank(t_push_swap *stacks);

#endif
