/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:54 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/29 20:58:24 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
 * Check that arg isn't NULL ans starts w' a nb or a +/- sign
 * Check that is there is a + or -, it's followed by a nb
 * Check that the rest of the str consists only of nb
 */
int	is_valid_number(char *arg)
{
	int	i;

	if (!arg || (!is_digit(arg[0]) && arg[0] != '+' && arg[0] != '-'))
		return (1);
	if ((arg[0] == '+' || arg[0] == '-') && !is_digit(arg[1]))
		return (1);
	i = 1;
	while (arg[i])
	{
		if (!is_digit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

// Return 1 if a duplicate is found, otherwise 0
int	has_duplicate(t_stack *a, int n)
{
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

// Iterate through the linked list and free each element
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

// Free the a stack w' free_stack and write Error on stderr
void	free_errors(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
