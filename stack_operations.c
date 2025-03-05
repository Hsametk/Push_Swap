/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:55:29 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/05 15:00:41 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	i;
	long	result;

	i = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * i);
}
void	create_stacks(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (!(*stack_a) || !(*stack_b))
	{
		if (*stack_a)
			free(*stack_a);
		if (*stack_b)
			free(*stack_b);
		exit(1);
	}
	**stack_a = NULL;
	**stack_b = NULL;
}

void	append(t_stack **stack, int value)
{
	t_stack *new_node;
	t_stack *current;

    // Yeni düğüm için bellek ayır
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ; // Bellek tahsisi başarısız olduysa çık
	new_node->data = value; // Yeni düğüme değer ata
	new_node->next = NULL;  // Yeni düğümün bağlantısını NULL yap
    // Eğer liste boşsa, yeni düğümü başlangıç yap
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
    // Listenin sonuna kadar ilerle
	current = *stack;
	while (current->next != NULL)
		current = current->next;
    // Yeni düğümü mevcut son düğümün arkasına bağla
	current->next = new_node;
}

void	fill_stack(t_stack ***stack_a, char **args)
{
	int		i;
	long	num;

	i = 0;
	while (args[i] != NULL)
	{
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
		append(*stack_a, (int)num);
		i++;
	}
}

int	stack_size(t_stack *stack)
{
	t_stack	*iter;
	int		i;

	if (!stack)
		return (0);
	iter = stack;
	i = 1;  // 1'den başla çünkü ilk elemanı sayıyoruz
	while (iter->next != NULL)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}