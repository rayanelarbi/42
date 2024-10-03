/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:14:26 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/16 15:25:32 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*int main()
{
	int x = 1;
	int y = 2;

	printf("Before function call x = %d, y = %d\n", x, y);

	ft_swap(&x, &y);

	printf("After function call x = %d, y = %d\n", x, y);

	return 0;
}*/
