/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:42:00 by rlarbi            #+#    #+#             */
/*   Updated: 2024/10/23 17:14:25 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < ac)
	{
		j = 2;
		while (j < ac)
		{
			if (ft_strcmp(av[j - 1], av[j]) > 0)
				ft_swap(&av[j - 1], &av[j]);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		str = av[i++];
		while (*str)
			ft_putchar(*str++);
		ft_putchar('\n');
	}
	return (0);
}
