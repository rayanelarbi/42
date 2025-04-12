/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:37:04 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/12 20:25:08 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft+/include/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_proc
{
	pid_t	pid1;
	pid_t	pid2;
}	t_proc;

void	error(void);
void	exe(char *av, char **env_path);
void	launch_children(char **av, char **env, int *fd, t_proc *proc);

#endif
