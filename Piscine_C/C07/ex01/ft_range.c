/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:53:24 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/30 12:12:54 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	if (min >= max)
		return (NULL);
	range = (int *)malloc(sizeof(int) * (max - min) + 1);
	if (range == 0)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*int	main(void)
{
	int	i = 0;
	int	min = 10;
	int	max = 20;
	int	*str = ft_range(min, max);
	
	while(i < (max - min))
	{
		printf("%d\n", str[i]);
		i++;
	}
	free(str);
	return (0);
}*/
/*void	ft_putnbr(int nb)
{
	char	c;

	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write (1, &c, 1);
}*/
/*int	main(void)
{
	int	*range;
	int	i;
	int	min;
	int	max;

	min = 10;
	max = 20;
	range = ft_range(min, max);
	if (range == NULL)
		return (1);
	i = 0;
	while (i < (max - min))
	{
		ft_putnbr(range[i]);
		if (i < (max - min) - 1)
			write (1, "\n", 1);
		i++;
	}
	write (1, "\n", 1);

	free(range);

	return (0);
}*/
