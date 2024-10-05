/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:12:41 by rlarbi            #+#    #+#             */
/*   Updated: 2024/09/25 19:34:39 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
			write(1, str++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
