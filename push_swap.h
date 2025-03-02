/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:26:29 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/03 15:31:27 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int data;
	struct s_stack* next;
	int index;
} t_stack;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library_srcs/ft_printf/ft_printf.h"
#include "library_srcs/libft/libft.h"

char    **argumans_controller(char **argv, int argc);
void	create_stacks(t_stack ***stack_a, t_stack ***stack_b);
void    fill_stack(t_stack ***stack_a, char **args);
void	append(t_stack **stack, int value);
int stack_size(t_stack *stack);
void	radix_sort(t_stack **a, t_stack **b, int size);
// void	destroy_stack(t_stack *stack);
// bool	is_full(t_stack *stack);
// bool	is_empty(t_stack *stack);
// bool	pop(t_stack *stack, int *item);
// bool	push(t_stack *stack, int item);
// bool	peek(t_stack *stack, int *item);
// void    sa(t_stack *stack);
// void	list_stack(t_stack *stack);
#endif