/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:12:32 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/05 17:39:09 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = res * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (res * sign);
}
// int main(void)
// {
//     const char *test1 = "   -12345";
//     const char *test2 = "42";
//     const char *test3 = "   +00789";
//     const char *test4 = "  \t\n\r\v\f123abc";
//     const char *test5 = "abc123";

//     printf("Test 1: %d\n", ft_atoi(test1));  // Devrait afficher -12345
//     printf("Test 2: %d\n", ft_atoi(test2));  // Devrait afficher 42
//     printf("Test 3: %d\n", ft_atoi(test3));  // Devrait afficher 789
//     printf("Test 4: %d\n", ft_atoi(test4));  // Devrait afficher 123
//     printf("Test 5: %d\n", ft_atoi(test5));  // Devrait afficher 0

//     return (0);
// }
