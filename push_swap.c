/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/03 20:55:15 by samcu            ###   ########.fr       */
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

	// Sayıları indexle
	index_stack(*stack_a);

	// Sıralamadan önce stack'in durumunu yazdır
	ft_printf("\nSıralamadan önce:");
	print_stack(*stack_a, "Stack A");
	print_stack(*stack_b, "Stack B");

	radix_sort(stack_a, stack_b);

	// Sıralamadan sonra stack'in durumunu yazdır
	ft_printf("\nSıralamadan sonra:");
	print_stack(*stack_a, "Stack A");
	print_stack(*stack_b, "Stack B");

	return (0);
}
/*
ft_strlcpy ve ft_calloc'ın hatalarını düzelt.
  İlk olarak sayıları al OK
  Gelen sayılar tek tırnağın içerisinde ise split fonksiyonu çağırılır ve boşluğa göre sayıları ayırır. OK
  Hata varsa bunu free le çünkü splitte mallocluyosun. 
  Eğer sayılar tek tırnak içerisinde değilse direk sayıları stack_a'ya ekler.
  sadece + ve - varsa hata mesajı 
  int max dan büyükse alma
  Stack operasyonlarını dene swap push fln.
*/