// #include "../push_swap.h"

// static int	get_max_bits(t_stack **a)
// {
// 	t_stack	*head;
// 	int		max_bits;
// 	int		max_num;
// 	int		min_num;

// 	head = *a;
// 	max_bits = 0;
// 	max_num = head->index;
// 	min_num = head->index;
	
// 	// En büyük ve en küçük sayıyı bul
// 	while (head)
// 	{
// 		if (head->index > max_num)
// 			max_num = head->index;
// 		if (head->index < min_num)
// 			min_num = head->index;
// 		head = head->next;
// 	}

// 	// Mutlak değerce en büyük sayının bit sayısını bul
// 	max_num = (max_num > -min_num) ? max_num : -min_num;

// 	while ((max_num >> max_bits) != 0)
// 		max_bits++;

// 	return (max_bits + 1);  // İşaret biti için +1
// }

// void	radix_sort(t_stack **a, t_stack **b)
// {
// 	int		max_bits;
// 	int		bit_pos;
// 	int		current_size;
// 	t_stack	*tmp;

// 	if (!a || !*a || !b)
// 		return ;
// 	bit_pos = 0;
// 	max_bits = get_max_bits(a);
// 	while (bit_pos < max_bits)
// 	{
// 		current_size = stack_size(*a);
// 		while (current_size > 0)
// 		{
// 			tmp = *a;
// 			if (((tmp->index >> bit_pos) & 1) == 0)
// 				push_b(a, b);
// 			else
// 				rotate_a(a);
// 			current_size--;
// 		}
// 		while (*b)
// 			push_a(b, a);
// 		bit_pos++;
// 	}
// }
#include "../push_swap.h"

// En büyük bit sayısını hesapla
static int get_max_bits(t_stack **a)
{
    t_stack *head = *a;
    int max_bits = 0;
    int max_num = head->index;

    // En büyük sayıyı bul
    while (head)
    {
        if (head->index > max_num)
            max_num = head->index;
        head = head->next;
    }

    // En büyük sayının bit sayısını hesapla
    while ((max_num >> max_bits) != 0)
        max_bits++;

    return max_bits;
}

void radix_sort(t_stack **a, t_stack **b)
{
    int max_bits;
    int bit_pos;
    int current_size;

    if (!a || !*a || !b)
        return;

    max_bits = get_max_bits(a);

    for (bit_pos = 0; bit_pos < max_bits; bit_pos++)
    {
        current_size = stack_size(*a);

        // Bit kontrolüne göre elemanları taşı
        for (int i = 0; i < current_size; i++)
        {
            if ((((*a)->index >> bit_pos) & 1) == 0)
                push_b(a, b);
            else
                rotate_a(a);
        }

        // Yığına geri taşı
        while (*b)
            push_a(b, a);
    }
}
