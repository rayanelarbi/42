/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:27:17 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/19 23:39:16 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Add the contents of a buffer to an existing string,
// While handling the freeing of the original string's memory
char	*ft_add_and_free(char *line, char *buffer)
{
	char	*new_line;

	new_line = ft_strjoin(line, buffer);
	free(line);
	return (new_line);
}

// Reads a file, store the data in a buffer and add it to an existing string
// Checks if a newline character was encountered to interrupt the read loop
char	*ft_read_and_add(int fd, char *line)
{
	char	*buffer;
	int		bytes_read;

	if (!line)
		line = ft_calloc(1, 1);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_add_and_free(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

// It copies the part of the line that precedes (and optionally includes),
// the first newline character
char	*ft_extract_until_newline(char *line)
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
	if (line[i] && line[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	return (str);
}

// Once a line has been extracted, this function deletes that part of the
// Original line, leaving only the rest
char	*ft_remove_until_newline(char *line)
{
	size_t	i;
	size_t	j;
	char	*remaining_line;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	remaining_line = ft_calloc((ft_strlen(line) - i + 1), sizeof(*line));
	if (!remaining_line)
		return (NULL);
	while (line[++i])
		remaining_line[j++] = line[i];
	remaining_line[j] = '\0';
	free(line);
	return (remaining_line);
}

char	*get_next_line(int fd)
{
	char		*output_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_and_add(fd, line);
	if (!line)
		return (NULL);
	output_line = ft_extract_until_newline(line);
	line = ft_remove_until_newline(line);
	return (output_line);
}

/*int	main(void)
{
	char	*line;

	int fd = open("test.txt", O_RDONLY); // Ouvrir le fichier en lecture
	if (fd < 0)
	{
		perror("Erreur lors de l'ouverture du fichier");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL) // Lire une ligne à la fois
	{
		printf("%s", line); // Afficher la ligne lue
		free(line);         // Libérer la mémoire de la ligne après utilisation
	}
	close(fd); // Fermer le fichier
	return (0);
}*/
