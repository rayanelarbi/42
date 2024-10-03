/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:59:25 by rlarbi            #+#    #+#             */
/*   Updated: 2024/10/01 15:20:22 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min) + 1);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}
/*int	main()
{
	int	i = 0;
	int	min = 1;
	int	max = 10000;
	int	*tab = NULL;
	int	size;
	
	size = ft_ultimate_range(&tab, min, max);
	while (tab[i])
	{
		printf("%d\n", tab[i]);
		i++;
	}
	if (size != -1)
		free(tab);
	return (0);
}*/
