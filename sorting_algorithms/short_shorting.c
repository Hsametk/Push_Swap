/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_shorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samcu <samcu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:03:28 by samcu             #+#    #+#             */
/*   Updated: 2025/03/05 22:10:56 by samcu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
}

static void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->data;
	second = (*a)->next->data;
	third = (*a)->next->next->data;

	if (first > second && second < third && first < third)
		swap_a(a);
	else if (first > second && second > third)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (first > second && second < third && first > third)
		rotate_a(a);
	else if (first < second && second > third && first < third)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(a);
}

static int	find_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	min = tmp->data;
	pos = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

static void	sort_four(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = find_min_pos(*a);
	// En küçük sayıyı stack'in üstüne getir
	while (min_pos > 0)
	{
		if (min_pos <= 2)
			rotate_a(a);
		else
			reverse_rotate_a(a);
		min_pos = find_min_pos(*a);
	}
	push_b(a, b);  // En küçük sayıyı B'ye at
	sort_three(a); // Kalan 3 sayıyı sırala
	push_a(b, a);  // En küçük sayıyı geri al
}

static void	sort_five(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		min_pos = find_min_pos(*a);
		// En küçük sayıyı en kısa yoldan üste getir
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				rotate_a(a);
		}
		else
		{
			while (min_pos++ < size)
				reverse_rotate_a(a);
		}
		push_b(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		push_a(b, a);
}

void	short_shorting(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}