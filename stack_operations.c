/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:55:29 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/26 15:27:54 by samcu            ###   ########.fr       */
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

void	append(t_stack **stack, int value)
{
	if ((*stack)->data == NULL)
		(*stack)->data = value;

}