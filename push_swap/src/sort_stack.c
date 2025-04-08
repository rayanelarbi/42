/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:25:46 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/08 20:20:13 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Rotate both stacks a and b until the elements of a and b pointed by
// cheapest_block are at the top of their respective stacks
static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_block)
{
	while (*b != cheapest_block->target && *a != cheapest_block)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

// Reverse rotate both stacks a and b until the elements of a and b pointed by
// cheapest_block are at the top of their respective stacks
static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_block)
{
	while (*b != cheapest_block->target && *a != cheapest_block)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

// Move the cheapest block of a to b
static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*block;
	t_stack	*target;

	block = get_cheapest(*a);
	target = block->target;
	if (block->above_median && target->above_median)
	{
		while (block != *a && target != *b)
			rotate_both(a, b, block);
	}
	else if (!block->above_median && !target->above_median)
	{
		while (block != *a && target != *b)
			rev_rotate_both(a, b, block);
	}
	push_cheapest(a, block, 'a');
	push_cheapest(b, target, 'b');
	pb(b, a);
}

// Move the cheapest block of b to a
static void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*target;

	target = (*b)->target;
	push_cheapest(a, target, 'a');
	pa(a, b);
}

// Sort the stacks with the turk algorithm
void	turk_algorithm(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_size(*a);
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len-- > 3 && !is_sorted(*a))
	{
		a_initializer(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		b_initializer(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_block_top(a);
}
