/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:21:50 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/29 14:01:49 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Convert a string in long
static long	ft_atol(const char *str)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

// Add a new block in the end of the stack
static void	add_block(t_stack **stack, int value)
{
	t_stack	*last_block;
	t_stack	*block;

	if (!stack)
		return ;
	block = malloc(sizeof(t_stack));
	if (!block)
		return ;
	block->next = NULL;
	block->nb = value;
	if (!(*stack))
	{
		*stack = block;
		block->prev = NULL;
	}
	else
	{
		last_block = get_last_block(*stack);
		last_block->next = block;
		block->prev = last_block;
	}
}

// Initialize the a stack with the args in the CLI
void	init_stack_a(t_stack **a, char **array)
{
	int		i;
	long	nbr;

	i = 0;
	while (array[i])
	{
		if (is_valid_number(array[i]))
			free_errors(a);
		nbr = ft_atol(array[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(a);
		if (has_duplicate(*a, (int)nbr))
			free_errors(a);
		add_block(a, (int)nbr);
		i++;
	}
}
