/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/03/03 15:34:56 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	//t_stack	*iter;
	char	**args;

	if (argc < 2)
		return (0);
	args = argumans_controller(argv, argc);// Fonksiyon bildirimi header'da olmalı
    create_stacks(&stack_a, &stack_b);// Fonksiyon adı kontrol edildi
    fill_stack(&stack_a, args);// Bildirim header dosyasına eklenmeli
	// iter = *stack_a;
	// while (iter->next != NULL)
	// {
	// 	ft_printf("%d\n", iter->data);
	// 	iter = iter->next;
	// }
	radix_sort(stack_a, stack_b, stack_size(*stack_a));
}
/*
  İlk olarak sayıları al OK
  Gelen sayılar tek tırnağın içerisinde ise split fonksiyonu çağırılır ve boşluğa göre sayıları ayırır. OK
  Hata varsa bunu free le çünkü splitte mallocluyosun. 
  Eğer sayılar tek tırnak içerisinde değilse direk sayıları stack_a'ya ekler.
  sadece + ve - varsa hata mesajı 
  int max dan büyükse alma
  Stack operasyonlarını dene swap push fln.
*/