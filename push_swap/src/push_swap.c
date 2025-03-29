/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:08:27 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/29 18:49:54 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	char	**tmp;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (EXIT_FAILURE);
	else if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		init_stack_a(&a, tmp);
	}
	else
	{
		init_stack_a(&a, av + 1);
	}
	if (!is_sorted(a))
	{
		if (stack_size(a) == 3)
			sort_three(&a);
		else if (stack_size(a) == 2)
			sa(&a);
		else
			turk_algorithm(&a, &b);
	}
	return (0);
}

// Algorithm that sort the three first elements of the stack
void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if (*a == max)
		ra(a, false);
	else if ((*a)->next == max)
		rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}
