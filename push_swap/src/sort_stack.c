/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:25:46 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/02 14:31:03 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	turk_algorithm(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_size(*a);
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
