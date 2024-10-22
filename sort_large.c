#include "push_swap.h"

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
void	radix_sort(t_push_swap *stacks)
{
    int max_bits = find_max_digits(stacks->a);  // Количество бит
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
                // Оцениваем, нужно ли вращать вперед или назад
                if (find_min_rotations(stacks->a, j))
                    ra(stacks);
                else
                    rra(stacks);
            }
            else
            {
                pb(stacks->a, stacks->b);
            }
            j++;
        }

        while (stacks->b->size > 0)
        {
            pa(stacks->a, stacks->b);
        }
        i++;
    }
}
