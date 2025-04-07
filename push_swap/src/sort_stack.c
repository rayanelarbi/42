/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:25:46 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/07 18:44:25 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void prepare_both(t_stack **a, t_stack **b)
{
	t_stack *cheapest;
	t_stack *head_a = *a;
	t_stack *head_b = *b;
	cheapest = get_cheapest(*a);
	while (*a != cheapest)
	{
		if (cheapest->above_median)
			ra(a);
		else
			rra(a);
		*a = (*a)->next;
	}
	while (*b != cheapest->target)
	{
		if (cheapest->target->above_median)
			rb(b);
		else
			rrb(b);
		*b = (*b)->next;
	}
	set_index(*a);
	set_index(*b);
	pb(b, a);
}



// Move the min block on top of a
// static void min_block_top(t_stack **a)
// {
// 	while ((*a)->nb != find_min(*a)->nb)
// 	{
// 		if (find_min(*a)->above_median)
// 			ra(a);
// 		else
// 			rra(a);
// 	}
// }

void	turk_algorithm(t_stack **a, t_stack **b)
{
	stack_size(*a);
	if (stack_size(*a) > 3)
		pb(b, a);
	if (stack_size(*a) > 3)
		pb(b, a);
	while (stack_size(*a) > 3)
	{
		printf("in the while\n");
		a_initializer(*a, *b);
		prepare_both(a, b);
	}

}
