/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:08:39 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/21 12:00:22 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// While 1 Advance the ptr s1 as long as the current char belongs to set
// While 2 decrease i as long as the char at position i belongs to set
// Return substr from index 0 to i inclusive is extracted and returned
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
/*int	main(void)
{
	char	*str;
	char	*set;
	char	*result;

	// Test &
	str = "   Hello, World!   ";
	set = " ";
	result = ft_strtrim(str, set);
	printf("Trim de \"%s\" avec set \"%s\" : \"%s\"\n", str, set, result);
	free(result);
	// Trim 2 sides
	str = "---42Nice---";
	set = "-";
	result = ft_strtrim(str, set);
	printf("Trim de \"%s\" avec set \"%s\" : \"%s\"\n", str, set, result);
	free(result);
	// Test 3
	str = "##Welcome##";
	set = "#";
	result = ft_strtrim(str, set);
	printf("Trim de \"%s\" avec set \"%s\" : \"%s\"\n", str, set, result);
	free(result);
	// Test 4
	str = "Hello!";
	set = "#";
	result = ft_strtrim(str, set);
	printf("Trim de \"%s\" avec set \"%s\" : \"%s\"\n", str, set, result);
	free(result);
	// Nothing
	str = "";
	set = "#";
	result = ft_strtrim(str, set);
	printf("Trim de chaîne vide \"%s\" avec set \"%s\" : \"%s\"\n", str, set,
		result);
	free(result);
	// Set void
	str = "42Nice";
	set = "";
	result = ft_strtrim(str, set);
	printf("Trim de \"%s\" avec set vide \"%s\" : \"%s\"\n", str, set, result);
	free(result);
	return (0);
}*/
