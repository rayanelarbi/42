/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:19:25 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/18 21:54:11 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
/*int	main()
{
	char str1[] = "rayane";
	char str2[] = "raYane";
	char str3[] = "";

	printf("Test %s\n", ft_strupcase(str1));
	printf("Test %s\n", ft_strupcase(str2));
	printf("Test %s\n", ft_strupcase(str3));
	
	return (0);
}*/
