/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:31:42 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/15 17:28:08 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	negative;
	int	l;
	int	i;

	negative = 1;
	l = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = -negative;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			l = l * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (l * negative);
}
/*int	main()
{
	ft_atoi("---++--+123ab567");
	printf("%d\n", ft_atoi("---++--+123ab567"));
}*/
