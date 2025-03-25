/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:29:44 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/19 17:53:28 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swaps the first 2 elements at the top of stack
static void	swap(t_stack **top)
{
	if (!*top || !(*top)->next)
		return ;
	*top = (*top)->next;
	(*top)->prev->prev = *top;
	(*top)->prev->next = (*top)->next;
	if ((*top)->next)
		(*top)->next->prev = (*top)->prev;
	(*top)->next = (*top)->prev;
	(*top)->prev = NULL;
}

// For the stack a
void	sa(t_stack **a, bool print)
{
	swap(a);
	if (print == false)
		write(1, "sa\n", 3);
}

// For the stack b
void	sb(t_stack **b, bool print)
{
	swap(b);
	if (print == false)
		write(1, "sb\n", 3);
}

// For both at the same time
void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print == false)
		write(1, "ss\n", 3);
}
