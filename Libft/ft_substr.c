/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:50:54 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/20 22:04:44 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
/*int	main(void)
{
	char	*str;
	char	*substr;

	// Test 1 (Should return "World")
	str = "Hello, World!";
	substr = ft_substr(str, 7, 5);
	printf("Sous-chaîne de \"%s\" à partir de 7, longueur 5 : \"%s\"\n", str,
		substr);
	free(substr);
	// Test 2 (Should return "World!")
	substr = ft_substr(str, 7, 50);
	printf("Sous-chaîne de \"%s\" à partir de 7, longueur 50 : \"%s\"\n", str,
		substr);
	free(substr);
	// Test 3 (Should return nothing)
	substr = ft_substr(str, 20, 5);
	printf("Sous-chaîne de \"%s\" à partir de 20, longueur 5 : \"%s\"\n", str,
		substr);
	free(substr);
	// Test 4 (Should return nothing)
	substr = ft_substr(str, 5, 0);
	printf("Sous-chaîne de \"%s\" à partir de 5, longueur 0 : \"%s\"\n", str,
		substr);
	free(substr);
	// Test 5 (Should return nothing)
	str = "";
	substr = ft_substr(str, 0, 5);
	printf("Sous-chaîne de chaîne vide : \"%s\"\n", substr);
	free(substr);
	return (0);
}*/
