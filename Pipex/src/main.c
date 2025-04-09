/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:22:20 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/09 17:17:37 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

int	main(void)
{
	int		fd[2];
	pid_t	pid;
	char	buffer[100];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		// Child: write in pipe
		close(fd[0]);
		write(fd[1], "hello\n", 6);
	}
	else
	{
		// Parent: read from pipe
		close(fd[1]);
		read(fd[0], buffer, 100);
		write(1, buffer, 6);
	}
}
