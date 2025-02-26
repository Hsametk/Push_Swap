/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:25:10 by hakotu            #+#    #+#             */
/*   Updated: 2025/02/26 15:29:30 by samcu            ###   ########.fr       */
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
/*
	Gelen sayılar tek tırnağın içerisinde ise split fonksiyonu çağırılır ve boşluğa göre sayıları ayırır.
  Eğer sayılar tek tırnak içerisinde değilse direk sayıları stack_a'ya ekler.
  Stack_a'ya eklenen sayılar kontrol edilir.
  Eğer stack_a'da tek sayı varsa hata döner.
  Eğer stack_a'da çift sayı varsa stack_b'ye sayıların yarısı push edilir.
  Stack_b'ye push edilen sayılar kontrol edilir.
  Eğer stack_b'de tek sayı varsa hata döner.
  Eğer stack_b'de çift sayı varsa stack_a'ya sayıların yarısı push edilir.


*/