/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:30:07 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/16 17:48:57 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	r;
	int	y;

	r = *a;
	y = *b;
	*a = r / y;
	*b = r % y;
}
/*int main() {
	int x = 10;
	int y = 3;
	
	printf("Before x = %d, y = %d\n", x, y);
	ft_ultimate_div_mod(&x, &y);
	printf("Before x = %d, y = %d\n", x, y);
	
	return 0;
}*/
