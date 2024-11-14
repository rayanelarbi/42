/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:45:00 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/13 17:28:58 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*int main(void)
{
    const char *str1 = "Hello";
    const char *str2 = "Helium";
    const char *str3 = "Hello";
    const char *str4 = "He";
    size_t n;

    // Test 1: Comparaison avec les premiers 3 caractères identiques
    n = 3;
    printf("Comparaison de \"%s\" et \"%s\" avec n = %zu : %d\n", str1, str2, n, ft_strncmp(str1, str2, n));

    // Test 2: Comparaison complète de deux chaînes identiques
    n = 5;
    printf("Comparaison de \"%s\" et \"%s\" avec n = %zu : %d\n", str1, str3, n, ft_strncmp(str1, str3, n));

    // Test 3: Comparaison où l'une des chaînes est plus courte
    n = 4;
    printf("Comparaison de \"%s\" et \"%s\" avec n = %zu : %d\n", str1, str4, n, ft_strncmp(str1, str4, n));

    // Test 4: Comparaison avec n = 0 (devrait retourner 0)
    n = 0;
    printf("Comparaison de \"%s\" et \"%s\" avec n = %zu : %d\n", str1, str2, n, ft_strncmp(str1, str2, n));

    // Test 5: Comparaison où les chaînes diffèrent dès le premier caractère
    const char *str5 = "Apple";
    const char *str6 = "Banana";
    n = 1;
    printf("Comparaison de \"%s\" et \"%s\" avec n = %zu : %d\n", str5, str6, n, ft_strncmp(str5, str6, n));

    return 0;
}*/
