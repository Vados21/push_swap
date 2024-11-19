# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 13:17:55 by vshpilev          #+#    #+#              #
#    Updated: 2024/08/29 13:17:57 by vshpilev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Имя программы
NAME = push_swap

# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0 -g

# Все .c файлы для проекта
SRCS = push_swap.c \
	   ft_atoi_ver_2.c \
	   utility_func.c \
	   push.c \
	   reverse_rotate.c \
	   rotate.c \
	   sort_four_and_five.c \
	   radix_sort.c \
	   sort_two_and_three.c \
	   swap.c \
	   validation_and_parse.c \
	   error_and_duble.c \
	   radix_utils.c \

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
