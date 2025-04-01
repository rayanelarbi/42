/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:17:27 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/01 16:35:00 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Move the first element from the src stack to the dst stack
static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_block;

	if (!*src)
		return ;
	push_block = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_block->prev = NULL;
	if (!*dst)
	{
		*dst = push_block;
		push_block->next = NULL;
	}
	else
	{
		push_block->next = *dst;
		push_block->next->prev = push_block;
		*dst = push_block;
	}
}

// Push the first element of b to a
void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

// // Push the first element of a to b
void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
