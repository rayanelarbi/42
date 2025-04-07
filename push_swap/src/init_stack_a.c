/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:02:50 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/08 00:08:18 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Set the index for each block in the stack and the median
void	set_index(t_stack *a)
{
	int	i;
	int	m_value;

	i = 0;
	m_value = stack_size(a) / 2;
	while (a)
	{
		a->i = i;
		if (i <= m_value)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		++i;
	}
}

// To know which block in b is the closest smallest to each block in a
// And if there is no closest smallest, we take the biggest in b
static void	set_target_a(t_stack **a, t_stack **b)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*target;
	long	flag;

	flag = LONG_MIN;
	head_a = *a;
	while (head_a)
	{
		head_b = *b;
		while (head_b)
		{
			if (head_a->nb > head_b->nb && head_b->nb > flag)
			{
				flag = head_b->nb;
				target = head_b;
			}
			head_b = head_b->next;
		}
		if (flag == LONG_MIN)
			head_a->target = find_max(*b);
		else
			head_a->target = target;
		head_a = head_a->next;
	}
}

// To calculate the push cost for each block
static void	push_cost(t_stack **a, t_stack **b)
{
	t_stack	*head_a;
	int		sum;
	int		len_a;
	int		len_b;

	len_a = stack_size(*a);
	len_b = stack_size(*b);
	head_a = *a;
	while (head_a)
	{
		sum = 0;
		if (head_a->above_median)
			sum += head_a->i;
		else
			sum += (len_a - (head_a->i));
		if (head_a->target->above_median)
			sum += head_a->target->i;
		else
			sum += (len_b - head_a->target->i);
		head_a->push_cost = sum;
		head_a = head_a->next;
	}
}

// To know the cheapest to push to b
void	set_cheapest(t_stack **a)
{
	t_stack	*head_a;
	t_stack	*cheapest_block;

	head_a = *a;
	cheapest_block = *a;
	while (head_a)
	{
		head_a->cheapest = false;
		if (head_a->push_cost < cheapest_block->push_cost)
		{
			cheapest_block = head_a;
		}
		head_a = head_a->next;
	}
	cheapest_block->cheapest = true;
}

// For initialize the a stack, the index, target push_cost etc.
void	a_initializer(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(&a, &b);
	push_cost(&a, &b);
	set_cheapest(&a);
}
