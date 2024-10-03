/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:09:57 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/18 21:18:31 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	a;

	i = 0;
	while (str[i])
	{
		a = str [i];
		if (!(a >= 32 && a <= 126))
			return (0);
		i++;
	}
	return (1);
}
/*int	main()
{
	printf("Test %d\n", ft_str_is_printable("56&"));
	printf("Test %d\n", ft_str_is_printable(""));
	printf("Test %d\n", ft_str_is_printable("	"));
	
	return (0);
}*/
