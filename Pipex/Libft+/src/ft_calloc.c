/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:08:34 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:26:33 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	str;
	void	*ptr;

	str = count * size;
	if (count != 0 && str / count != size)
		return (NULL);
	ptr = malloc(str);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, str);
	return (ptr);
}
