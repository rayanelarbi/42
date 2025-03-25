/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:01:38 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/24 16:52:53 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Move the last element of the stack and place it at the top
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = get_last_block(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

// For the stack a
void	rra(t_stack **a, bool print)
{
	reverse_rotate(a);
	if (print == false)
		write(1, "rra\n", 4);
}

// For the stack b
void	rrb(t_stack **b, bool print)
{
	reverse_rotate(b);
	if (print == false)
		write(1, "rrb\n", 4);
}

// For both at the same time
void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == false)
		write(1, "rrr\n", 4);
}
