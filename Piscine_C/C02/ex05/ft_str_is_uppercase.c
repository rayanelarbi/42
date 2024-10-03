/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:28:46 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/18 20:36:52 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	a;

	i = 0;
	while (str[i])
	{
		a = str[i];
		if (!(a >= 'A' && a <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}
/*int main ()
{
	printf("Test %d\n", ft_str_is_uppercase("TEST"));
	printf("Test %d\n", ft_str_is_uppercase("dEST"));
	printf("Test %d\n", ft_str_is_uppercase(""));
	printf("Test %d\n", ft_str_is_uppercase("&&"));
	
	return (0);
}*/
