/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:39:51 by bozil             #+#    #+#             */
/*   Updated: 2024/09/22 12:08:55 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./rush.h"

// grid = la map avec chaque lignes et colonnes independantes
void	print_grid(int **grid)
{
	char	c;
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

// permet de verifier qu'il y a pas deux fois la meme valeur 
// dans la meme ligne et la meme colonne
int	is_valid(int **grid, int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == value || grid[i][col] == value)
			return (0);
		i++;
	}
	return (1);
}
