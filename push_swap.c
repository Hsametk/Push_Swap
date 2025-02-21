/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:23:55 by samcu             #+#    #+#             */
/*   Updated: 2025/02/21 18:46:11 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main(void)
// {
//   // create a stack with a capacity of 5
//   Stack *stack_a = create_stack(5);
  
//   // if we failed to create the stack, exit with an error message and status
//   if (stack_a == NULL)
//   {
//     printf("Error creating stack.\n");
//     return 1;
//   }
  
//   // the stack SHOULD be empty initially
//   if (is_empty(stack_a)) printf("Stack is empty\n");
  
//   // after pushing item 2 onto the stack, the stack size should now be 1
//   push(stack_a, 2);
//   printf("Stack size: %d\n", stack_a->size);
  
//   // push 4 more items onto the stack, which should now be full
//   push(stack_a, 9);
//   push(stack_a, 4);
//   push(stack_a, 7);
//   push(stack_a, 8);

//   // // the stack should now be full, with size 5
//   // if (is_full(stack)) printf("Stack is full.\n");
//   // printf("Stack size: %d\n", stack->size);
  
//   // // if we try to push another item onto the stack, it should fail
//   // bool try_push = push(stack, 5);
//   // if (try_push == false) printf("Push failed.\n");
  
//   // // if we peek at the top item in the stack, the value should be 8
//   // int peek_val = 0;
//   // peek(stack, &peek_val);
//   // printf("Peek Val: %d\n", peek_val);
  
//   // // pop off the 5 items on the stack, notice the "last in, first out" order
//   // int pop_val = 0;
//   // for (int i = 0; i < 5; i++)
//   // {
//   //   // pop each item and print it
//   //   pop(stack, &pop_val);
//   //   printf("Popped Value: %d\n", pop_val);
//   // }
  
//   // // if we try to pop an item off an empty stack, it will fail
//   // bool try_pop = pop(stack, &pop_val);
//   // if (try_pop == false) printf("Pop Failed.\n");
  
//   // // if we try to peek at an item on an empty stack, it will fail
//   // bool try_peek = peek(stack, &peek_val);
//   // if (try_peek == false) printf("Peek Failed.\n");
//   list_stack(stack_a);
//   printf("----------------");
//   sa(stack_a);
//   // destroy the stack since we are done working with it
//   destroy_stack(stack_a);
  
//   return 0;
// }

int main(int argc, char *argv[])
{
  t_stack **stack_a;
  t_stack **stack_b;
  char    *args;

  create_stack(&stack_a, &stack_b);
}