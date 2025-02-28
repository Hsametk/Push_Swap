/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:55:29 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/28 12:15:47 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stacks(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!(*stack_a) || !(*stack_b))
		exit(1);
	**stack_a = NULL;
	**stack_b = NULL;
}

// 7 10 5 50 42 458 472 211 
void	append(t_stack **stack, int value)
{
	if ((*stack)->data == NULL)
		(*stack)->data = value;

}