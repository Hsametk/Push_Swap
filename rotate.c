/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:07:46 by samcu             #+#    #+#             */
/*   Updated: 2025/02/26 12:17:23 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack*	iter;
	t_stack*	first;

    if (!*stack || !(*stack)->next)
		return;
	first = *stack;
    iter = *stack;
    while (iter->next != NULL)
        iter = iter->next;
    iter->next = first;
    stack= first->next;
	first->next = NULL;
}

void rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
void rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}