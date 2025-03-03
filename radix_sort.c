#include "push_swap.h"

static int	get_max_bits(t_stack **a)
{
	t_stack	*head;
	int		max_bits;
	int		max;

	head = *a;
	max_bits = 0;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		max_bits;
	int		bit_pos;
	int		current_size;
	t_stack	*tmp;

	if (!a || !*a || !b)
		return ;
	bit_pos = 0;
	max_bits = get_max_bits(a);
	while (bit_pos < max_bits)
	{
		current_size = stack_size(*a);
		while (current_size > 0)
		{
			tmp = *a;
			if (((tmp->index >> bit_pos) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			current_size--;
		}
		while (*b)
			push_a(b, a);
		bit_pos++;
	}
}