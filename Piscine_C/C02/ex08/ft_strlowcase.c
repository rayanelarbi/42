/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:55:06 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/22 15:52:54 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
/*int	main()
{
	char str1[] = "RAYANE";
	char str2[] = "RAyANE";
	char str3[] = "";

	printf("Test %s\n", ft_strlowcase(str1));
	printf("Test %s\n", ft_strlowcase(str2));
	printf("Test %s\n", ft_strlowcase(str3));
	
	return (0);
}*/
