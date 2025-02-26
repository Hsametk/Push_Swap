/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:46:37 by samcu             #+#    #+#             */
/*   Updated: 2025/02/23 15:15:22 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sa(t_stack *stack_a) {   
//     int first; 
//     int second;

//     // Yığında en az 2 eleman olup olmadığını kontrol et
//     if (stack_a->size <= 1) {
//         printf("Swap yapılamaz: Yeterli eleman yok.\n");
//         return;
//     }

//     // Üstteki iki elemanı çıkar
//     pop(stack_a, &first);
//     pop(stack_a, &second);

//     // Yer değiştir ve tekrar ekle
//     push(stack_a, first);
//     push(stack_a, second);
// 	list_stack(stack_a);
// }
// void	sb(t_stack *stack_b) {   
//     int first; 
//     int second;

//     // Yığında en az 2 eleman olup olmadığını kontrol et
//     if (stack_b->size <= 1) {
//         printf("Swap yapılamaz: Yeterli eleman yok.\n");
//         return;
//     }

//     // Üstteki iki elemanı çıkar
//     pop(stack_b, &first);
//     pop(stack_b, &second);

//     // Yer değiştir ve tekrar ekle
//     push(stack_b, first);
//     push(stack_b, second);
// }

// void ss(t_stack *stack_a, t_stack *stack_b)
// {
// 	sa(stack_a);
// 	sb(stack_b);
// }

// void pa(t_stack *stack_a, t_stack stack_b)
// {
	
// }
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

    if ((*stack)->size < 2)
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