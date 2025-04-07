/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:33:25 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/07 17:33:53 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Update the target block for each element of the b stack, and found the
// correct block in the a stack
static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*head_a;
	t_stack	*target;
	long	flag;

	while (b)
	{
		flag = LONG_MAX;
		head_a = a;
		while (head_a)
		{
			if (head_a->nb > b->nb && head_a->nb < flag)
			{
				flag = head_a->nb;
				target = head_a;
			}
			head_a = head_a->next;
		}
		if (flag == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

// For initialize the b stack, the index, target
void	b_initializer(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
