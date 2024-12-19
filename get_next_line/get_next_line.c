/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:27:17 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/19 14:11:18 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_line(char *line, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(line, buffer);
	free(line);
	return (tmp);
}

char	*ft_read_line(int fd, char *line)
{
	char	*buffer;
	int		char_read;

	if (!line)
		line = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[char_read] = '\0';
		line = ft_free_line(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*ft_extract_line(char *line)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	str = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	while (line[i] && line[i] == '\n')
		str[i++] = '\n';
	return (str);
}

char	*ft_first_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(line) - i + 1), sizeof(*line));
	if (!str)
		return (NULL);
	while (line[++i])
		str[j++] = line[i];
	str[j] = '\0';
	free(line);
	return (str);
}

// TODO: Faire la fonction GNL
// TODO: Join, allouer et libérer la memory
// TODO: Lire la première ligne avec read
// TODO: Prendre la ligne de sortie et la renvoyé
