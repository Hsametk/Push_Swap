/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/23 16:38:43 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
  t_stack **stack_a;
  t_stack **stack_b;
  char    *args;
  if (argc < 2)
    return (0);
  is_arg_null(argv);
  argc_control(argv, argc);
  create_stack(&stack_a, &stack_b);
  
  
}