/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:30:10 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/16 17:26:25 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*int main() {
	int a = 16;
	int b = 3;
	int div;
	int mod;

	//Call function
	ft_div_mod(a, b, &div, &mod);
	printf(" %d par %d, Quotient = %d et le Reste = %d\n", a, b, div, mod);
	
	return 0;
}*/	
