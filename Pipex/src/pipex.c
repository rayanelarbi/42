/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:18:40 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/12 19:32:37 by rlarbi           ###   ########.fr       */
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
	close(pipe[1]);
	exe(av[2], env_path);
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
	close(pipe[0]);
	close(pipe[1]);
	exe(av[3], env_path);
}

int	main(int ac, char **av, char **env_path)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (ac != 5)
	{
		ft_putstr_fd("\033[0;31mERROR\033[0m\n", 2);
		ft_putstr_fd("Type : ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error();

	pid1 = fork();
	if (pid1 == -1)
		error();
	if (pid1 == 0)
		child_process(av, env_path, fd);

	pid2 = fork();
	if (pid2 == -1)
		error();
	if (pid2 == 0)
		parent_process(av, env_path, fd);

	// Parent ferme les deux extrémités du pipe pour éviter les fuites
	close(fd[0]);
	close(fd[1]);

	// Attend les deux processus enfants
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);

	return (WEXITSTATUS(status));
}

