/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:23:55 by samcu             #+#    #+#             */
/*   Updated: 2025/02/20 21:28:02 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
  // create a stack with a capacity of 5
  Stack *stack = create_stack(5);
  
  // if we failed to create the stack, exit with an error message and status
  if (stack == NULL)
  {
    printf("Error creating stack.\n");
    return 1;
  }
  
  // the stack SHOULD be empty initially
  if (is_empty(stack)) printf("Stack is empty\n");
  
  // after pushing item 2 onto the stack, the stack size should now be 1
  push(stack, 2);
  printf("Stack size: %d\n", stack->size);
  
  // push 4 more items onto the stack, which should now be full
  push(stack, 9);
  push(stack, 4);
  push(stack, 7);
  push(stack, 8);

  // the stack should now be full, with size 5
  if (is_full(stack)) printf("Stack is full.\n");
  printf("Stack size: %d\n", stack->size);
  
  // if we try to push another item onto the stack, it should fail
  bool try_push = push(stack, 5);
  if (try_push == false) printf("Push failed.\n");
  
  // if we peek at the top item in the stack, the value should be 8
  int peek_val = 0;
  peek(stack, &peek_val);
  printf("Peek Val: %d\n", peek_val);
  
  // pop off the 5 items on the stack, notice the "last in, first out" order
  int pop_val = 0;
  for (int i = 0; i < 5; i++)
  {
    // pop each item and print it
    pop(stack, &pop_val);
    printf("Popped Value: %d\n", pop_val);
  }
  
  // if we try to pop an item off an empty stack, it will fail
  bool try_pop = pop(stack, &pop_val);
  if (try_pop == false) printf("Pop Failed.\n");
  
  // if we try to peek at an item on an empty stack, it will fail
  bool try_peek = peek(stack, &peek_val);
  if (try_peek == false) printf("Peek Failed.\n");
  
  // destroy the stack since we are done working with it
  destroy_stack(stack);
  
  return 0;
}

// Returns a pointer to a Stack on the heap capable of storing capacity amount 
// of items.  Returns NULL if the Stack cannot be created.
Stack *create_stack(int capacity)
{
  // Don't allow stacks with a capacity <= 0
  if (capacity <= 0) return NULL;
  
  // allocate space for the stack on the heap, return NULL if malloc fails
  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) return NULL;
  
  // allocate enough space to store capacity number of items in collections
  stack->collection = malloc(sizeof(int) * capacity);

  // if the allocation of space for collection fails, we'll need to free the 
  // stack allocated on the heap before returning NULL to prevent a memory leak
  if (stack->collection == NULL)
  {
    free(stack);
    return NULL;
  }
  
  // set the capacity to the provided capacity, and the initialize size is zero
  stack->capacity = capacity;
  stack->size = 0;
  
  // return the pointer to the Stack on the heap
  return stack;
}

// Free's the dynamically allocated memory for the collection and the stack.
void destroy_stack(Stack *stack)
{
  free(stack->collection);
  free(stack);
}

// returns true if the stack is full, and false otherwise
bool is_full(Stack *stack)
{
  // if the stack size has reached the capacity, the stack is now full
  return stack->capacity == stack->size;
}

// returns true if the stack is empty, and false otherwise
bool is_empty(Stack *stack)
{
  return stack->size == 0;
}

// Attempts to push the provided item onto the stack, and returns true if it 
// was done successfully and false otherwise.  
bool push(Stack *stack, int item)
{
  // We cannot push an item onto the stack if it is full, so return false if so
  if (is_full(stack)) return false;
  
  // set the next available index in the collection array to the item 
  stack->collection[stack->size] = item;

  // increment the size of the stack (if another item is pushed to the stack 
  // immediately after this, it will be stored in the NEXT array index)
  stack->size++;
  
  // return true as we have successfully pushed an item onto the stack
  return true;
}

// Uses pass-by-pointer to "return" the item at the top of the stack using the 
// pointer parameter item.  Returns true if the item was peeked successfully 
// and false otherwise.  Note that peeking at the item at the top of the stack
// does NOT remove it from the stack (like popping the item does).
bool peek(Stack *stack, int *item)
{
  // We can't peek at next item in Stack if it is empty, so return false if so
  if (is_empty(stack)) return false;
  
  // de-reference item to "return" via the pointer parameter the item at the 
  // top of the stack (as arrays are zero-indexed, this is the index at one less
  // than the current size of the stack 
  *item = stack->collection[stack->size - 1];
  
  // return true as we have successfully peeked at the item at the top of the stack
  return true;
}

// Uses pass-by-pointer to "return" the item at the top of the stack using the 
// pointer parameter item.  Returns true if the item was popped successfully 
// and false otherwise.  Popping the item from the stack *removes* the item from
// the top of the stack (making the item "below" this item, if there is one, the 
// new top of the stack).
bool pop(Stack *stack, int *item)
{
  // We can't pop next item in the Stack if it is empty, so return false if so
  if (is_empty(stack)) return false;
  
  // Decrement the size of the stack to effectively "remove" the item from the 
  // stack... though we don't "delete" the item from the dynamically allocated 
  // collections array, this doesn't matter given the way we implement the 
  // Stack.  The value stored in the array will simply be overwritten if we 
  // push enough items onto the Stack.
  stack->size--;

  // De-reference item to "return" via the pointer parameter the item at the 
  // top of the stack (arrays are zero-indexed, so after decrementing the size 
  // of the stack by 1, the size will give the appropriate array index).
  *item = stack->collection[stack->size];
  
  // return true as we have successfully popped the item at the top of the stack
  return true;
}
