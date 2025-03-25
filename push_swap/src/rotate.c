/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:57:38 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/19 17:55:57 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Move the first element of the stack and place it last
static void	rotate(t_stack **stack)
{
	t_stack	*last_block;

	if (!*stack || !(*stack)->next)
		return ;
	last_block = get_last_block(*stack);
	last_block->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_block->next->prev = last_block;
	last_block->next->next = NULL;
}

// For the stack a
void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (print == false)
		write(1, "ra\n", 3);
}

// For the stack b
void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (print == false)
		write(1, "rb\n", 3);
}

// For both at the same time
void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print == false)
		write(1, "rr\n", 3);
}
