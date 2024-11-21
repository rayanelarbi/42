/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:08:39 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/21 14:09:50 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// While 1 Advance the ptr s1 as long as the current char belongs to set
// While 2 decrease i as long as the char at position i belongs to set
// Return substr from index 0 to i inclusive is extracted and returned
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	if (NULL == s1 || NULL == set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		++start;
	while (end >= 0 && ft_strchr(set, *(s1 + end)))
		--end;
	if (start > end)
		return (ft_strdup(""));
	trimmed = malloc((end - start) + 2);
	if (NULL == trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, (end - start) + 2);
	return (trimmed);
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
