/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/06 12:58:17 by hakotu           ###   ########.fr       */
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

// static void	cleanup_memory(t_stack **stack_a, t_stack **stack_b, char **args)
// {
// 	t_stack	*tmp;
// 	int		i;

// 	// Stack A'yı temizle
// 	while (*stack_a)
// 	{
// 		tmp = (*stack_a)->next;
// 		free(*stack_a);
// 		*stack_a = tmp;
// 	}
// 	free(stack_a);  // stack_a pointer'ını da free et

// 	// Stack B'yi temizle
// 	while (*stack_b)
// 	{
// 		tmp = (*stack_b)->next;
// 		free(*stack_b);
// 		*stack_b = tmp;
// 	}
// 	free(stack_b);  // stack_b pointer'ını da free et

// 	// args'ı temizle
// 	i = 0;
// 	while (args[i])
// 		free(args[i++]);
// 	free(args);
// }
static void cleanup_memory(t_stack **stack_a, t_stack **stack_b, char **args)
{
    t_stack *tmp;

    // Stack A'yı temizle
    if (stack_a)
    {
        while (*stack_a)
        {
            tmp = (*stack_a)->next;
            free(*stack_a);
            *stack_a = tmp;
        }
        free(stack_a); // `stack_a` pointer'ını serbest bırak
    }

    // Stack B'yi temizle
    if (stack_b)
    {
        while (*stack_b)
        {
            tmp = (*stack_b)->next;
            free(*stack_b);
            *stack_b = tmp;
        }
        free(stack_b); // `stack_b` pointer'ını serbest bırak
    }

    // Args'ı temizle
    if (args)
    {
        for (int i = 0; args[i]; i++)
            free(args[i]); // `args` içindeki her bir öğeyi serbest bırak
        free(args); // `args` dizisini serbest bırak
    }
}

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
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

	is_arg_digit(stack_a);
	is_arg_same(stack_a);

	// Eğer zaten sıralıysa hiçbir şey yapma
	if (!is_sorted(*stack_a))
	{
		if (stack_size(*stack_a) <= 5)
			short_shorting(stack_a, stack_b);
		else
		{
			index_stack(*stack_a);
			radix_sort(stack_a, stack_b);
		}
	}

	cleanup_memory(stack_a, stack_b, args);
	return (0);
}
// int - max ı algılamıyor.
//memory leakler var.
