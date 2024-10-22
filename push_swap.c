#include "push_swap.h"


//RADIX SORT

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack->top || !stack->top->next)
        return (1);

    current = stack->top;

    while (current->next)
    {
        if (current->data > current->next->data)
            return (0);
        current = current->next;
    }

    return (1);
}

int	find_min_rotations(t_stack *stack, int target_pos)
{
    int half_size;

    // Находим середину стека
    half_size = stack->size / 2;

    // Если элемент ближе к началу, используем ra
    if (target_pos <= half_size)
        return (1); // Вращаем вперед
    else
        return (0); // Вращаем назад
}

void	move_element_to_top(t_push_swap *stacks, int target_pos)
{
    if (find_min_rotations(stacks->a, target_pos))
    {
        while (target_pos > 0)
        {
            ra(stacks);
            target_pos--;
        }
    }
    else
    {
        while (target_pos < stacks->a->size)
        {
            rra(stacks);
            target_pos++;
        }
    }
}

int	find_max_digits(t_stack *stack)
{
    t_node	*current;
    int		max_value;
    int		max_digits;

    if (!stack || !stack->top)
        return (0);  // Возвращаем 0, если стек пуст

    current = stack->top;
    max_value = current->data;
    max_digits = 0;

    // Поиск максимального значения в стеке
    while (current != NULL)
    {
        if (current->data > max_value)
            max_value = current->data;
        current = current->next;
    }

    // Определение количества разрядов (цифр) в максимальном числе
    while (max_value != 0)
    {
        max_value /= 10;
        max_digits++;
    }

    return (max_digits);
}



// Прототипы вспомогательных функций
void    validate_input(int argc, char **argv);
t_stack *parse_input(int argc, char **argv);

int	main(int argc, char **argv)
{
    t_push_swap stacks;
    char **numbers;
    int new_argc;
    int i;

    //printf("Starting program...\n");  // debug

    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }

    if (argc == 2)
    {
        //printf("Processing single string input: %s\n", argv[1]);  // debug
        numbers = ft_split(argv[1], ' ');
        if (!numbers || !numbers[0])
        {
            write(1, "Error\n", 6);
            return (1);
        }
        new_argc = 0;
        while (numbers[new_argc])
        {
            //printf("Split word %d: %s\n", new_argc, numbers[new_argc]);  // debug
            new_argc++;
        }
        //printf("Validating input...\n"); //debug
        validate_input(new_argc, numbers);

        // Разбираем данные и создаем стек a
        stacks.a = parse_input(new_argc, numbers);
        i = 0;
        while (i < new_argc)
        {
            free(numbers[i]);
            i++;
        }
        free(numbers);
    }
    else
    {
        //printf("Processing multiple arguments\n");  // debug
        validate_input(argc - 1, argv + 1);
        stacks.a = parse_input(argc - 1, argv + 1);
    }

    stacks.b = malloc(sizeof(t_stack));
    stacks.b->top = NULL;
    stacks.b->size = 0;

    //printf("Checking if stack is sorted...\n");  // debug
    if (is_sorted(stacks.a))
    {
        free_stack(stacks.a);
        free_stack(stacks.b);
        //printf("Stack is already sorted.\n");  // debug
        return (0);
    }

    //printf("Stack size: %d\n", stacks.a->size); //debug
    if (stacks.a->size == 2)
    {
        //printf("sort two started\n"); //debug
        sort_two(&stacks);
    }
    else if (stacks.a->size == 3)
        sort_three(&stacks);
    else if (stacks.a->size == 4)
        sort_four(&stacks);
    else if (stacks.a->size == 5)
        sort_five(&stacks);
    else
    {
        //printf("Starting radix_sort...\n"); //debug
        radix_sort(&stacks);  // Radix сортировка для большого количества элементов
    }

    // Очистка памяти
    //printf("Sorting complete. Cleaning up...\n");//debug
    free_stack(stacks.a);
    free_stack(stacks.b);

    return (0);
}



