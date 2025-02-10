/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:46:31 by rlarbi            #+#    #+#             */
/*   Updated: 2024/12/20 17:25:14 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/get_next_line_bonus.h"

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
	static char	*line[FOPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	line[fd] = ft_read_and_add(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	output_line = ft_extract_until_newline(line[fd]);
	line[fd] = ft_remove_until_newline(line[fd]);
	return (output_line);
}

/*int	main(void)
{
	int fd1, fd2, fd3;
	char *line1, *line2, *line3;
	// Open multiple files to read.
	fd1 = open("test_file1.txt", O_RDONLY);
	fd2 = open("test_file2.txt", O_RDONLY);
	fd3 = open("test_file3.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("Error opening files");
		return (1);
	}
	// Read and print lines from multiple files.
	while ((line1 = get_next_line(fd1)) != NULL
		|| (line2 = get_next_line(fd2)) != NULL
		|| (line3 = get_next_line(fd3)) != NULL)
	{
		if (line1)
		{
			printf("File 1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("File 2: %s", line2);
			free(line2);
		}
		if (line3)
		{
			printf("File 3: %s", line3);
			free(line3);
		}
	}
	// Close the file descriptors.
	if (close(fd1) == -1 || close(fd2) == -1 || close(fd3) == -1)
	{
		perror("Error closing files");
		return (1);
	}
	return (0);
}*/
