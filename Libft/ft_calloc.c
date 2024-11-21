/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:08:34 by rlarbi            #+#    #+#             */
/*   Updated: 2024/11/21 14:05:49 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;
	unsigned long	i;

	i = 0;
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	while (count * size > i)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
