/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:50:54 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/21 14:17:30 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	substr_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	substr_len = s_len - start;
	if (len > substr_len)
		len = substr_len;
	str = malloc(len + 1);
	if (NULL == str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
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
