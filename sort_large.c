#include "push_swap.h"

// Функция для нахождения максимального значения в стеке
int find_max_value(t_stack *stack)
{
    t_node *current = stack->top;
    int max_value = current->data;

    while (current != NULL)
    {
        if (current->data > max_value)
            max_value = current->data;
        current = current->next;
    }
    return max_value;
}

// Функция для подсчета количества битов, необходимых для сортировки
int calculate_max_bits(int max_value)
{
    int bits = 0;
    while (max_value > 0)
    {
        max_value /= 2;
        bits++;
    }
    return bits;
}

// Основная функция для Radix Sort
void radix_sort(t_push_swap *stacks)
{
    int max_bits = calculate_max_bits(find_max_value(stacks->a));  // Количество бит
    int size = stacks->a->size;
    int i = 0;

    while (i < max_bits)
    {
        int j = 0;

        while (j < size)
        {
            int num = stacks->a->top->data;

            // Если бит на i позиции равен 1
            if ((num >> i) & 1)
            {
                ra(stacks);
            }
            else
            {
                pb(stacks->a, stacks->b);
            }
            j++;
        }

        // Перемещаем все элементы обратно из стека b в стек a
        while (stacks->b->size > 0)
        {
            pa(stacks->a, stacks->b);
        }
        i++;
    }
    print_stack(stacks->a, "a");
}
