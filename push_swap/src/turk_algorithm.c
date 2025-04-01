/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:02:50 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/01 16:48:58 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Set the index for each block in the stack and the median
static void	set_index(t_stack **a)
{
	int		i;
	t_stack	*head;
	int		m_value;

	m_value = stack_size(*a) / 2;
	head = *a;
	i = 0;
	while (head)
	{
		head->i = i;
		if (head->i <= m_value)
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
		i++;
	}
}

// To know which block in b is the closest smallest to each block in a
// And if there is no closest smallest, we take the biggest in b
void	set_target_a(t_stack **a, t_stack **b)
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

static void	print_i(t_stack **a)
{
	while (*a)
	{
		printf("the value is %d\n", (*a)->nb);
		printf("the index  is %d\n", (*a)->i);
		printf("the value is above median %d\n", (*a)->above_median);
		printf("the target value is %d\n", (*a)->target->nb);
		printf("the push cost is %d\n", (*a)->push_cost);
		printf("the cheapp is %d\n", (*a)->cheapest);
		(*a) = (*a)->next;
	}
}

// To calculate the push cost for each block
void	push_cost(t_stack **a, t_stack **b)
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

void	turk_algorithm(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_size(a);
	if (len > 3)
		pb(b, a);
	if (len > 3)
		pb(b, a);
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	push_cost(a, b);
	set_cheapest(a);
	print_i(a);
}
