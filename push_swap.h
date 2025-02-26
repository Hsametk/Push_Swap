/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:26:29 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/26 15:27:58 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int *data;
	struct s_stack* next;
	int	size;
} t_stack;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library_srcs/printf/ft_printf.h"
#include "library_srcs/libft/libft.h"


t_stack	*create_stacks(t_stack ***stack_a, t_stack ***stack_b);
// void	destroy_stack(t_stack *stack);
// bool	is_full(t_stack *stack);
// bool	is_empty(t_stack *stack);
// bool	pop(t_stack *stack, int *item);
// bool	push(t_stack *stack, int item);
// bool	peek(t_stack *stack, int *item);
// void    sa(t_stack *stack);
// void	list_stack(t_stack *stack);
#endif