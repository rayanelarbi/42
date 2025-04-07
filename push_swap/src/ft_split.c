/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:13:02 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/08 00:07:23 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Count the nb of words
static size_t	count_words(char const *s, char c)
{
	size_t	nb_words;
	int		inside_words;

	nb_words = 0;
	inside_words = 0;
	while (*s)
	{
		if (*s != c && !inside_words)
		{
			inside_words = 1;
			nb_words++;
		}
		else if (*s == c)
			inside_words = 0;
		s++;
	}
	return (nb_words);
}

// Allocate memory for each words
static char	*words_alloc(const char *start, const char *end)
{
	char	*words;
	size_t	i;

	i = 0;
	words = (char *)malloc((end - start + 1) * sizeof(char));
	if (words == NULL)
		return (NULL);
	while (start + i < end)
	{
		words[i] = start[i];
		i++;
	}
	words[i] = '\0';
	return (words);
}

// Free all split
static void	free_split(char **split, size_t index)
{
	while (index > 0)
		free(split[--index]);
	free(split);
}

// Split function
char	**ft_split(char const *s, char c)
{
	const char	*start;
	char		**split;
	size_t		i;

	i = 0;
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i] = words_alloc(start, s);
			if (!split[i])
				return (free_split(split, i), NULL);
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

/* // TODO: Main
int	main(void)
{
	char	**result;
	char	*phrase;
	char	separator;
	size_t	i;

	phrase = "Salut, demain vas-tu jouer a Valorant ?";
	separator = ' ';
	// Appeler la fonction ft_split
	result = ft_split(phrase, separator);
	if (!result)
	{
		printf("Erreur lors de l'exécution de ft_split.\n");
		return (1);
	}
	// Afficher les résultats
	printf("Résultat du split :\n");
	i = 0;
	while (result[i])
	{
		printf("[%zu] \"%s\"\n", i, result[i]);
		i++;
	}
	// Libérer la mémoire
	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return (0);
}*/
