/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:40:39 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/25 18:42:11 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 2))
	{
		if (!(nb % i))
			return (0);
		else
			i += 1;
	}
	return (1);
}
/*int main (void)
{
	printf("%d = %d\n", 7, ft_is_prime(7));
	printf("%d = %d\n", -12, ft_is_prime(-12));
	printf("%d = %d\n", 0, ft_is_prime(0));

	return (0);
}*/
