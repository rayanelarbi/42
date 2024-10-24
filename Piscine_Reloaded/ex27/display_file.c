/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:35:55 by rlarbi            #+#    #+#             */
/*   Updated: 2024/10/24 15:35:57 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

void	read_and_display(int fd)
{
	unsigned char	buffer[BUFFER_SIZE];
	ssize_t			bytes;

	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (read_error())
				close(fd);
			return ;
		}
		write(1, buffer, bytes);
	}
}

int	process_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (read_error());
	read_and_display(fd);
	close(fd);
	return (0);
}

int	main(int ac, const char **av)
{
	int	j;

	j = 1;
	if (ac < 2 && arg_error())
		return (1);
	if (ac > 2 && toomany_error())
		return (1);
	while (av[j])
	{
		if (process_file(av[j]) == 1)
			return (1);
		j++;
	}
	return (0);
}
