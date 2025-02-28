/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/28 17:12:01 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
  t_stack **stack_a;
  t_stack **stack_b;
  char    **args;
  if (argc < 2)
    return (0);
  
  args = argumans_controller(argv, argc);
  create_stack(&stack_a, &stack_b);
}
/*
  İlk olarak sayıları al 
	Gelen sayılar tek tırnağın içerisinde ise split fonksiyonu çağırılır ve boşluğa göre sayıları ayırır. Hata varsa bunu free le çünkü splitte mallocluyosun.
  Eğer sayılar tek tırnak içerisinde değilse direk sayıları stack_a'ya ekler.
  sadece + ve - varsa hata mesajı 
  int max dan büyükse alma
  Stack operasyonlarını dene swap push fln.
*/