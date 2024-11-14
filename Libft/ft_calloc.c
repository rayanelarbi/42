/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:08:34 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/14 15:19:38 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*int	main(void)
{
	size_t	count;
	size_t	size;
	int		*arr;

	count = 5;
	size = sizeof(int);
	// Allocation of memory for 5 integers
	arr = (int *)ft_calloc(count, size);
	if (arr == NULL)
	{
		printf("Allocation échouée.\n");
		return (1);
	}
	// Check the values after ft_calloc, they should be 0
	printf("Vérification des valeurs après ft_calloc:\n");
	for (size_t i = 0; i < count; i++)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
	}
	// Free the allocated memory
	free(arr);
	return (0);
}*/
