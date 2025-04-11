/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:39:46 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:29:10 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if ((dst == NULL) || (src == NULL))
		return (0);
	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	j = 0;
	while (src[j] && j < (dstsize - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
// int main(void)
// {
//     char src1[] = "Hello, world!";
//     char dst1[20];
//     char dst2[10];
//     char dst3[5];

//     // Test 1: Copy complète
//     size_t len1 = ft_strlcpy(dst1, src1, sizeof(dst1));
//     printf("Test 1 - Copie complète:\n");
//     printf("dst: '%s', Length of src: %zu\n\n", dst1, len1);

//     // Test 2: Copie tronquée
//     size_t len2 = ft_strlcpy(dst2, src1, sizeof(dst2));
//     printf("Test 2 - Copie tronquée:\n");
//     printf("dst: '%s', Length of src: %zu\n\n", dst2, len2);

//     // Test 3: Copie tronquée avec dstsize très petit
//     size_t len3 = ft_strlcpy(dst3, src1, sizeof(dst3));
//     printf("Test 3 - Copie tronquée avec dstsize très petit:\n");
//     printf("dst: '%s', Length of src: %zu\n\n", dst3, len3);

//     // Test 4: dstsize égal à 0
//     char dst4[20];
//     size_t len4 = ft_strlcpy(dst4, src1, 0);
//     printf("Test 4 - dstsize égal à 0:\n");
//     printf("dst: '%s', Length of src: %zu\n\n", dst4, len4);

//     // Test 5: src ou dst NULL
//     size_t len5 = ft_strlcpy(NULL, src1, sizeof(dst1)); // Test avec dst NULL
//     size_t len6 = ft_strlcpy(dst1, NULL, sizeof(dst1)); // Test avec src NULL

//     printf("Test 5 - src NULL:\n");
//     printf("Length of src: %zu\n\n", len5); // devrait retourner 0
//     printf("Test 5 - dst NULL:\n");
//     printf("Length of src: %zu\n\n", len6); // devrait retourner 0

//     return 0;
// }
