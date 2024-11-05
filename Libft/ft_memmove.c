/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:09:05 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/05 16:25:37 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if ((src == NULL) && (dest == NULL))
		return (0);
	i = 0;
	if ((size_t)dest - (size_t)src < len)
	{
		i = len - 1;
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	src1[] = "Hello, world!";
	char	overlap_src[] = "1234567890";
	char	dest1[20];

	// Cas 1 : Test sans chevauchement
	ft_memmove(dest1, src1, sizeof(src1)); // Copie src1 dans dest1
	printf("Cas 1 - Sans chevauchement : %s\n", dest1);

	// Cas 2 : Test avec chevauchement
	// On utilise overlap_src pour qu'il y ait chevauchement
	ft_memmove(overlap_src + 4, overlap_src, 6);
	// Move les 6 first char de overlap_src 4 positions vers la droite
	printf("Cas 2 - Avec chevauchement : %s\n", overlap_src);

	return (0);
}*/
