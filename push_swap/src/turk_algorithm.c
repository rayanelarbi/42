/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:02:50 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/29 18:59:36 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		(*a) = (*a)->next;
	}
}

void	turk_algorithm(t_stack **a, t_stack **b)
{
	pb(b, a);
	pb(b, a);
	set_index(a);
	set_target_a(a, b);
	print_i(a);
}
