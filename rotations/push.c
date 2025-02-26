/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:17:49 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/26 11:55:10 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	push(t_stack **src_stack, t_stack **dst_stack)
{
	t_stack	*head;

	if (stack_size(*src_stack) == 0)
		return ;
	head = *src_stack;
	*src_stack = head->next;
	head->next = *dst_stack;
	*dst_stack = head;
}

void push_a(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pa\n");
}
void push_a(t_stack **stack_b, t_stack **stack_a)
{
    push(stack_b, stack_a);
    ft_printf("pb\n");

}
