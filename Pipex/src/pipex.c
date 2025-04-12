/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:18:40 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/12 20:26:20 by rlarbi           ###   ########.fr       */
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

// Function that launch children
void	launch_children(char **av, char **env, int *fd, t_proc *proc)
{
	proc->pid1 = fork();
	if (proc->pid1 == -1)
		error();
	if (proc->pid1 == 0)
		child_process(av, env, fd);
	proc->pid2 = fork();
	if (proc->pid2 == -1)
		error();
	if (proc->pid2 == 0)
		parent_process(av, env, fd);
}

int	main(int ac, char **av, char **env_path)
{
	int		fd[2];
	t_proc	proc;
	int		status;

	if (ac != 5)
	{
		ft_putstr_fd("\033[0;31mERRORRRRRRRRRRRRR\033[0m\n", 2);
		ft_putstr_fd("Type : ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error();
	launch_children(av, env_path, fd, &proc);
	close(fd[0]);
	close(fd[1]);
	waitpid(proc.pid1, &status, 0);
	waitpid(proc.pid2, &status, 0);
	return (WEXITSTATUS(status));
}
