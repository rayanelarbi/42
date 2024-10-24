/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:12:46 by rlarbi            #+#    #+#             */
/*   Updated: 2024/10/23 16:13:20 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	index;
	long	a;

	a = nb;
	if (a <= 0)
	{
		return (0);
	}
	if (a == 1)
	{
		return (1);
	}
	index = 2;
	if (a >= 2)
	{
		while (index * index <= a)
		{
			if (index * index == a)
			{
				return (index);
			}
			index++;
		}
	}
	return (0);
}
