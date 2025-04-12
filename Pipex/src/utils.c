/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:19:40 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/12 17:03:16 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Print error on the stderr and exit
void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

// Free each elements of the tab and free the tab
static void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/* Function searches for the command in the directories specified in the
PATH environment variable. It returns the full path to the command if
it is found and executable, otherwise it returns NULL */
static char	*get_path(char *cmd, char **env_path)
{
	int		i;
	char	**path;
	char	*joined_path;
	char	*full_cmd;

	i = 0;
	while (env_path[i] && ft_strncmp(env_path[i], "PATH=", 5) != 0)
		i++;
	path = ft_split(env_path[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		joined_path = ft_strjoin(path[i], "/");
		full_cmd = ft_strjoin(joined_path, cmd);
		free(joined_path);
		if (access(full_cmd, X_OK) == 0)
		{
			free_tab(path);
			return (full_cmd);
		}
		free(full_cmd);
		i++;
	}
	free_tab(path);
	return (NULL);
}

/* Function take a string av containing a command and its arguments,
searches for the path to the command in the directories defined
in the PATH environment variable using the get_path function.
If the path is found, it tries to execute the command with execve */
void	exe(char *av, char **env_path)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], env_path);
	if (!path)
	{
		free_tab(cmd);
		error();
	}
	if (execve(path, cmd, env_path) == -1)
	{
		free(path);
		free_tab(cmd);
		error();
	}
	free(path);
	free_tab(cmd);
}
