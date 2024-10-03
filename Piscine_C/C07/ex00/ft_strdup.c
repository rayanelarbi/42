/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:39:49 by rlarbi            #+#    #+#             */
/*   Updated: 2024/10/01 22:04:15 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (0);
	j = 0;
	while (j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
int	main(void)
{
	char *copy;

	if (argc < 2)
	{
		ft_putstr("Erreur pas assez darg\n");
		return (1);
	}
	copy = ft_strdup(argv[1]);
	
	if (copy == NULL)
	{	
		ft_putstr("Error dallocation de memoire\n");
		return (1);
	}
	ft_putstr(copy);
	write (1, "\n", 1);
	char	*src;
	char	*dup;
	
	src = "SALUT";
	dup = ft_strdup(src);
	if (dup != 0)
	{
		printf("%s\n", src);
		printf("%s\n", dup);
	}
	free(dup);

	return (0);
}*/
