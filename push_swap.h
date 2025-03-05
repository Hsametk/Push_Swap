/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:26:29 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/04 13:58:48 by samcu            ###   ########.fr       */
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
#include <limits.h>  // INT_MIN ve INT_MAX için
#include "library_srcs/printf/ft_printf.h"
#include "library_srcs/libft/libft.h"

char    **argumans_controller(char **argv, int argc);
void	create_stacks(t_stack ***stack_a, t_stack ***stack_b);
void    fill_stack(t_stack ***stack_a, char **args);
void	append(t_stack **stack, int value);
int stack_size(t_stack *stack);
void	radix_sort(t_stack **a, t_stack **b);
void	is_arg_same(t_stack **a);
void	is_arg_digit(t_stack **a);
// void	destroy_stack(t_stack *stack);
// bool	is_full(t_stack *stack);
// bool	is_empty(t_stack *stack);
// bool	pop(t_stack *stack, int *item);
// bool	push(t_stack *stack, int item);
// bool	peek(t_stack *stack, int *item);
// void    sa(t_stack *stack);
// void	list_stack(t_stack *stack);

// Rotasyon fonksiyonları için prototipler
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

#endif