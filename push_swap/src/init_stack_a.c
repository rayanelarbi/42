/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:21:50 by rlarbi            #+#    #+#             */
/*   Updated: 2025/03/27 18:06:01 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *str)
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

void	init_stack_a(t_stack *a, char **array)
{
	int		i;
	long	nbr;

	i = 0;
	while (array[i])
	{
		if (is_valid_number(array[i]))
			free_errors(&a);
		nbr = ft_atol(array[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			free_errors(&a);
		}
		add_block(&a, (int)nbr);
		if (has_duplicate(a, (int)nbr))
		{
			printf("number is already in stackk\n");
		}
		i++;
	}
}

void	add_block(t_stack **a, int value)
{
	t_stack	*last;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_errors(a);
		return ;
	}
	return ;
	new->nb = value;
	new->next = NULL;
	if (a == NULL)
		return ;
	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = get_last_block(*a);
		last->next = new;
		new->prev = last;
	}
}
int	main(void)
{
	t_stack	*a;

	a = NULL;
	add_block(&a, 45);
	add_block(&a, -77);
	add_block(&a, 8);
	printf("is value already in stack: %d\n", has_duplicate(a, 98));
}
