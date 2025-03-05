/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/05 14:00:06 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Stack'i yazdırmak için yardımcı fonksiyon
void	print_stack(t_stack *stack, char *stack_name)
{
	t_stack	*iter;

	ft_printf("\n%s içeriği:\n", stack_name);
	if (!stack)
	{
		ft_printf("(boş)\n");
		return ;
	}
	iter = stack;
	while (iter)
	{
		ft_printf("%d(index:%d) ", iter->data, iter->index);
		iter = iter->next;
	}
	ft_printf("\n");
}

void	index_stack(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		index;

	i = stack;
	while (i)
	{
		index = 0;
		j = stack;
		while (j)
		{
			if (i->data > j->data)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

static void	cleanup_memory(t_stack **stack_a, t_stack **stack_b, char **args)
{
	t_stack	*tmp;
	int		i;

	// Stack A'yı temizle
	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			tmp = (*stack_a)->next;
			free(*stack_a);
			*stack_a = tmp;
		}
		free(stack_a);
	}

	// Stack B'yi temizle
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
		free(stack_b);
	}

	// args'ı temizle
	if (args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**args;

	if (argc < 2)
		return (0);
	args = argumans_controller(argv, argc);
	create_stacks(&stack_a, &stack_b);
	fill_stack(&stack_a, args);

	// Sayıların geçerli aralıkta olduğunu ve tekrar etmediğini kontrol et
	is_arg_digit(stack_a);
	is_arg_same(stack_a);
	index_stack(*stack_a);
	radix_sort(stack_a, stack_b);
	cleanup_memory(stack_a, stack_b, args);
	return (0);
}
// int - max ı algılamıyor.
//memory leakler var.
