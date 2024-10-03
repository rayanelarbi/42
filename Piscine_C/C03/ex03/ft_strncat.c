/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:51:18 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/24 18:36:17 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	c;
	unsigned int	d;

	c = 0;
	d = 0;
	while (dest[c] != '\0')
		c++;
	while (src[d] != '\0' && d < nb)
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
	return (dest);
}
/*int main()
{
    char dest[50] = "Bonjour, ";
    char src[] = "monde magnifique!";
	

	unsigned int nb = 5;

    ft_strncat(dest, src, nb);

    printf("Résultat de la concaténation : %s\n", dest);

    return 0;
}*/
