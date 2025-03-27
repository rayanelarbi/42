/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:02:14 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/27 13:33:09 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Return the last element of the stack
t_stack	*get_last_block(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// Find the biggest block in the stack and return it
t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_block;

	if (!stack)
		return (NULL);
	max_block = stack;
	while (stack)
	{
		if (stack->nb > max_block->nb)
			max_block = stack;
		stack = stack->next;
	}
	return (max_block);
}

// Find the smallest block in the stack and return it
t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_block;

	if (!stack)
		return (NULL);
	min_block = stack;
	while (stack)
	{
		if (stack->nb < min_block->nb)
			min_block = stack;
		stack = stack->next;
	}
	return (min_block);
}

// Return the size of a stack
int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

// Check if the stack is sorted
bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while(stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (false);
		stack = stack->next;
	}
	return (true);
}
