/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:29:49 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:29:33 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*int	main(void)
{
	const char	*haystack1 = "Hello, world!";
	const char	*needle1 = "world";
	const char	*needle2 = "planet";
	const char	*needle3 = "";
	size_t		len;
	const char	*haystack2 = "This is just a test";
	const char	*needle4 = "test";

	// Test 1: Trouver "world" dans "Hello, world!" avec len suffisamment grand
	len = 12;
	printf("Recherche de \"%s\" dans \"%s\" avec len = %zu : %s\n", needle1,
		haystack1, len, ft_strnstr(haystack1, needle1, len));
	// Test 2: Rechercher un mot inexistant ("planet")
	len = 12;
	printf("Recherche de \"%s\" dans \"%s\" avec len = %zu : %s\n", needle2,
		haystack1, len, ft_strnstr(haystack1, needle2,
			len) ? "Found" : "Not found");
	// Test 3: Rechercher une chaîne vide (doit retourner haystack)
	len = 5;
	printf("Recherche de chaîne vide dans \"%s\" avec len = %zu : %s\n",
		haystack1, len, ft_strnstr(haystack1, needle3, len));
	// Test 4: Longueur de recherche trop courte pour contenir needle
	len = 5;
	printf("Recherche de \"%s\" dans \"%s\" avec len = %zu : %s\n", needle1,
		haystack1, len, ft_strnstr(haystack1, needle1,
			len) ? "Trouvé" : "Non trouvé");
	// Test 5: needle à la toute fin de haystack
	len = 19;
	printf("Recherche de \"%s\" dans \"%s\" avec len = %zu : %s\n", needle4,
		haystack2, len, ft_strnstr(haystack2, needle4,
			len) ? "Trouvé" : "Non trouvé");
	return (0);
}*/
