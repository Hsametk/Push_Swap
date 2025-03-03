/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:46:37 by samcu             #+#    #+#             */
/*   Updated: 2025/03/03 13:25:29 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void list_stack(t_stack *stack) {
//     if (is_empty(stack)) {
//         printf("Yığın boş!\n");
//         return;
//     }
//     printf("Yığın elemanları (üstten alta):\n");
//     for (int i = stack->size - 1; i >= 0; i--) {
//         printf("%d\n", stack->collection[i]);
//     }
// }

void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (stack_size(*stack) < 2)
        return ;  
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}
void    swap_a(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}