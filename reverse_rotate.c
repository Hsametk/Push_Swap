/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:45:15 by samcu             #+#    #+#             */
/*   Updated: 2025/02/26 12:51:00 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *iter;
    t_stack *prev;

    // Eğer liste boşsa veya tek bir eleman içeriyorsa, işlem yapma
    if (!*stack || !(*stack)->next)
        return;

    // İteratör ve önceki işaretçiyi başlat
    iter = *stack;
    prev = NULL;

    // Son düğüme ulaşırken bir önceki düğümü de sakla
    while (iter->next != NULL)
    {
        prev = iter;
        iter = iter->next;
    }

    // Son düğümün yeni baş olmasını sağla
    iter->next = *stack;

    // Önceki düğümün next'ini NULL yaparak sonlandır
    prev->next = NULL;

    // Yeni baş düğümü stack'e atayın
    *stack = iter;
}
void reverse_rotate_a(t_stack **stack_a)
{
    reverse_rotate(stack_a);
	ft_printf("rra\n");

}
void reverse_rotate_b(t_stack **stack_b)
{
    reverse_rotate(stack_b);
	ft_printf("rrb\n");

}
void rrr(t_stack **stack_a , t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
	ft_printf("rrr\n");

}