/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:47:46 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/18 17:03:35 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src [i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*int main(void) {
    char src[] = "Bonjour, le monde!";
    char dest[20]; // Assurez-vous que dest a suffisamment d'espace

    // Test 1 : Copier 10 caractères
    ft_strncpy(dest, src, 10);
    printf("Test 1 (n=10) : %s\n", dest); // Devrait afficher "Bonjour, "

    // Test 2 : Copier 5 caractères
    ft_strncpy(dest, src, 5);
    printf("Test 2 (n=5) : %s\n", dest); // Devrait afficher "Bonj"

    // Test 3 : Copier 20 caractères (plus que la longueur de src)

    // Test 4 : Copier 0 caractères
    ft_strncpy(dest, src, 0);
    printf("Test 4 (n=0) : '%s'\n", dest);
    return 0;
}*/
