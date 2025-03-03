/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:55:29 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/03 13:59:27 by hakotu           ###   ########.fr       */
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
//to-do ilk önce int çevirmek lzm
void	fill_stack(t_stack ***stack_a , char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		append(*stack_a, ft_atoi(args[i]));
		i++;
	}
}

int	stack_size(t_stack *stack)
{
	t_stack	*iter;
	int		i;

	iter = stack;
	i = 0;
	while (iter->next != NULL)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}