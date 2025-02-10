/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:09:05 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:28:11 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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

	// Cas 1 : Test without overlap
	ft_memmove(dest1, src1, sizeof(src1)); // Copy src1 in dest1
	printf("Cas 1 - Without overlap : %s\n", dest1);

	// Cas 2 : Test with overlap
	// We use overlap_src so that there is an overlap
	ft_memmove(overlap_src + 4, overlap_src, 6);
	// Move the 6 first char of overlap_src 4 positions to the right
	printf("Cas 2 - With overlap : %s\n", overlap_src);

	return (0);
}*/
