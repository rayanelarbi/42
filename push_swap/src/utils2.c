/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:51:28 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/13 14:37:07 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Algorithm that sort the three first elements of the stack
void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

// Move the min block on top of a
void	min_block_top(t_stack **a)
{
	while ((*a)->nb != find_min(*a)->nb)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

// Free each str inside the tab and the tab
void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Print error msg and return EXIT_FAILURE
void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
