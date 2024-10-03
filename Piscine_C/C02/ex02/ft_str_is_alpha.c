/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:04:11 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/18 19:06:39 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	char	a;
	int		i;

	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		a = str[i];
		if (!((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
/*int main()
{
	printf("1 %d\n", ft_str_is_alpha("salut"));
	printf("2 %d\n", ft_str_is_alpha("salut11"));
	printf("3 %d\n", ft_str_is_alpha(""));

}*/
