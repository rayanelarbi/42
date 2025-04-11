/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:18:40 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/11 21:00:22 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Child process that run inside the fork, take the FILE_IN and put the OUTPUT
inside the left side of the pipe and close the pipe[0] (not needed here) and
run the cmd av[2] thanks to env_path */
void	child_process(char **av, char **env_path, int *pipe)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0644);
	if (fd == -1)
		error();
	dup2(pipe[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipe[0]);
	e(av[2], env_path);
}

/* Parent process that take the data from the pipe (right side) and change
the OUTPUT for the FILE_OUT and close the pipe[1] (not needed here) and
run the cmd av[3] thanks to env_path */
void	parent_process(char **av, char **env_path, int *pipe)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error();
	dup2(pipe[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe[1]);
	e(av[3], env_path);
}

int	main(int ac, char **av, char **env_path)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("\033[0;31mError\033[0m\n", 2);
		ft_putstr_fd("Type : ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	else
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(av, env_path, pipe);
		parent_process(av, env_path, pipe);
	}
	return (0);
}
