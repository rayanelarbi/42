/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:03:38 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/23 11:16:08 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (new_word && str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			else if (!new_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			new_word = 0;
		}
		else
		{
			new_word = 1;
		}
		i++;
	}
	return (str);
}
/*int	main()
{
	char str[] = "rAyAnE T hshoiso ff 56 gTTT";
	
	ft_strcapitalize(str);
	printf("%s", str);
	return (0);
}*/
