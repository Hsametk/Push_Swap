/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:46:37 by samcu             #+#    #+#             */
/*   Updated: 2025/02/21 13:47:37 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(Stack *stack_a) {   
    int first; 
    int second;

    // Yığında en az 2 eleman olup olmadığını kontrol et
    if (stack_a->size <= 1) {
        printf("Swap yapılamaz: Yeterli eleman yok.\n");
        return;
    }

    // Üstteki iki elemanı çıkar
    pop(stack_a, &first);
    pop(stack_a, &second);

    // Yer değiştir ve tekrar ekle
    push(stack_a, first);
    push(stack_a, second);
	list_stack(stack_a);
}
void	sb(Stack *stack_b) {   
    int first; 
    int second;

    // Yığında en az 2 eleman olup olmadığını kontrol et
    if (stack_b->size <= 1) {
        printf("Swap yapılamaz: Yeterli eleman yok.\n");
        return;
    }

    // Üstteki iki elemanı çıkar
    pop(stack_b, &first);
    pop(stack_b, &second);

    // Yer değiştir ve tekrar ekle
    push(stack_b, first);
    push(stack_b, second);
}

void ss(Stack *stack_a, Stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void pa(Stack *stack_a, Stack stack_b)
{
	
}
void list_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("Yığın boş!\n");
        return;
    }
    printf("Yığın elemanları (üstten alta):\n");
    for (int i = stack->size - 1; i >= 0; i--) {
        printf("%d\n", stack->collection[i]);
    }
}