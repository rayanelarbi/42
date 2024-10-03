/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:52:31 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/18 20:26:35 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	a;
	int	i;

	i = 0;
	while (str[i])
	{
		a = str[i];
		if (!(a >= 'a' && a <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
/*int main ()
{
	printf("Test %d\n", ft_str_is_lowercase("rayane"));
	printf("Test %d\n", ft_str_is_lowercase("rDayane"));
	printf("Test %d\n", ft_str_is_lowercase(""));
	printf("Test %d\n", ft_str_is_lowercase("&&"));

	return (0);
}*/
