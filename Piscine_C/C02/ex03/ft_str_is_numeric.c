/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:36:51 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/18 19:47:00 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	char	a;
	int		i;

	i = 0;
	while (str[i])
	{
		a = str[i];
		if (!(a >= '0' && a <= '9'))
			return (0);
		i++;
	}
	return (1);
}
/*int main()
{
	printf("test %d\n", ft_str_is_numeric(""));
	return 0;
}*/
