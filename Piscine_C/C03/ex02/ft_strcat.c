/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:21:36 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/24 20:28:16 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (dest[size] != '\0')
		size++;
	while (src[i] != '\0')
	{
		dest[size] = src[i];
		i++;
		size++;
	}
	dest[size] = '\0';
	return (dest);
}
/*int main()
{
    // Déclarer deux chaînes, avec suffisamment d'espace pour la concaténation
    char dest[50] = "Hello, ";  // Destination avec assez d'espace
    char src[] = "world!";      // Source à ajouter

    // Appel de la fonction ft_strcat
    ft_strcat(dest, src);

    // Afficher le résultat
    printf("Résultat de la concaténation : %s\n", dest);

    return 0;
}*/
