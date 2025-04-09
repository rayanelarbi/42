/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:22:20 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/09 19:35:59 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

int	main(int ac, char **av)
{
	int arr[] = {1, 2, 3, 1, 2, 3};
	int sizeArr = sizeof(arr) / sizeof(int);
	int fd[2];
	int id;
	int start;
	int end;

	id = fork();
	if (pipe(fd) == -1)
		return (error_exit);

	if (id == -1)
		return (error_exit);

	if (id == 0)
	{
		start = 0;
		end = sizeArr / 2;
	}
	else
	{
		start = sizeArr / 2;
		end = sizeArr;
	}
}
