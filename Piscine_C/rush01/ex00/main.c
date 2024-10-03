/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:54:33 by bozil             #+#    #+#             */
/*   Updated: 2024/09/22 12:09:07 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"

// malloc permet d'allouer de la memoire
int	**init_grid(void)
{
	int	i;
	int	j;
	int	**grid;

	i = 0;
	grid = malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		j = 0;
		grid[i] = malloc(sizeof(int) * 4);
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}

// free permet de liberer la memoire allouer par malloc
void	free_all(int *constraints, int **grid)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	free(constraints);
}

// argc et argv permettent d'ecrire les valeurs via le terminal
int	main(int argc, char **argv)
{
	int	*contraints;
	int	**grid;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	contraints = malloc(sizeof(int) * 16);
	if (!parse(argv[1], contraints))
	{
		free(contraints);
		return (1);
	}
	grid = init_grid();
	if (solve(contraints, grid, 0, 0))
	{
		print_grid(grid);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	free_all(contraints, grid);
	return (0);
}
