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

// Определение узла стека
typedef struct s_node
{
    int				data;
    struct s_node	*next;
}				t_node;

// Определение стека
typedef struct s_stack
{
    t_node	*top;
    int		size;
}				t_stack;

// Определение структуры push_swap
typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
    int operation_count;
}				t_push_swap;

// Операции со стеками
void	sa(t_push_swap *stacks);
void	sb(t_push_swap *stacks);
void	ss(t_push_swap *stacks);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void	ra(t_push_swap *stacks);
void	rb(t_push_swap *stacks);
void	rr(t_push_swap *stacks);
void	rra(t_push_swap *stacks);
void	rrb(t_push_swap *stacks);
void	rrr(t_push_swap *stacks);

// Вспомогательные функции
void	error(void);
void    validate_input(int argc, char **argv);
int		main(int argc, char **argv);
void    push(t_stack *src, t_stack *dst);
void    reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	find_mins(t_push_swap *stacks, int *min1, int *min2);
void	extract_mins(t_push_swap *stacks);
void	sort_four(t_push_swap *stacks);
void	sort_five(t_push_swap *stacks);
int		find_max_bits(t_stack *stack);
void	radix_sort(t_push_swap *stacks);
void	three_nice(t_push_swap *stacks, int first, int second, int third);
void	sort_three(t_push_swap *stacks);
void	sort_two(t_push_swap *stacks);

// Функции для работы со строками
void	*ft_free(char **res, size_t pos);
void	ft_word(char const *str, size_t *first, size_t *last, char c);
size_t	ft_count(char const *str, char c);
char	*ft_fill(char const *str, size_t first, size_t last);
char	**ft_split(char const *str, char c);

// Вспомогательные функции для стека
void	swap(t_stack *stack);
t_stack	*parse_input(int argc, char **argv);
int is_sorted(t_stack *stack);
void print_stack(t_stack *stack, char *stack_name);
void free_stack(t_stack *stack);
void push_to_stack(t_stack *stack, int num);
int find_max_index(t_stack *stack);

#endif
