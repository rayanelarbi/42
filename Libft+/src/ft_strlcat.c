/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:04:13 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:29:06 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (src[j] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
/*int main(void)
{
	char dst[20] = "Hello";
	const char *src = " World!";
	size_t dstsize = 15; // Size is superior to the size of dst

	printf("Avant ft_strlcat:\n");
	printf("dst = \"%s\"\n", dst);
	printf("src = \"%s\"\n", src);
	printf("dstsize = %zu\n", dstsize);

	// Call ft_strlcat
	size_t result = ft_strlcat(dst, src, dstsize);

	printf("\nAfter ft_strlcat:\n");
	printf("dst = \"%s\"\n", dst);
	printf("Len total voulue (retour de ft_strlcat) = %zu\n", result);

	return (0);
}*/
