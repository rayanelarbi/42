/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boschwie <boschwie@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:23:01 by boschwie          #+#    #+#             */
/*   Updated: 2024/09/29 20:23:42 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rush.h"

void	handle_error(void)
{
	write(2, "Dict Error\n", 11);
}

void	add_entry(t_dict **dict, int *size, char *line)
{
	long long	number;
	char		*words;
	char		*sep;

	number = ft_atoll(line);
	sep = line;
	while (*sep != ':')
		sep++;
	if (*sep != ':')
		handle_error();
	words = ft_strdup(sep + 1);
	if (!words)
		handle_error();
	(*dict)[*size].number = number;
	(*dict)[*size].words = words;
	(*size)++;
}

void	parse_file(char *file_path, t_dict **dict, int *dict_size)
{
	int		fd;
	char	buffer[4096];
	char	*line;
	int		bytes_read;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		handle_error();
	*dict = malloc(sizeof(t_dict) * 128);
	if (!(*dict))
		handle_error();
	*dict_size = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read < 0)
		handle_error();
	buffer[bytes_read] = '\0';
	line = buffer;
	while (*line)
	{
		if (*line == '\n')
			line++;
		else
		{
			add_entry(dict, dict_size, line);
			while (*line && *line != '\n')
				line++;
		}
	}
	close(fd);
}
