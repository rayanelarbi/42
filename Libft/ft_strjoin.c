/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:36:10 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/19 18:29:25 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Allocate (using malloc(3)) and return a new string,
 * resulting from the concatenation of s1 and s2.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
/*int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;

	s1 = "Bonjour, ";
	s2 = "comment ça va ?";
	// Call ft_strjoin
	result = ft_strjoin(s1, s2);
	if (!result)
	{
		printf("Erreur : allocation mémoire échouée.\n");
		return (1);
	}
	// Print result
	printf("Chaîne 1 : \"%s\"\n", s1);
	printf("Chaîne 2 : \"%s\"\n", s2);
	printf("Résultat de ft_strjoin : \"%s\"\n", result);
	// Free
	free(result);
	return (0);
}*/
