/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:34:35 by bozil             #+#    #+#             */
/*   Updated: 2024/09/22 12:08:45 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./rush.h"

// verifier que les valeurs soit affichable sur la map
int	check_constraints(int *constraints, int **grid)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (count_visible_from_left(grid[i]) != constraints[8 + i]
			|| count_visible_from_right(grid[i])
			!= constraints[12 + i])
		{
			return (0);
		}
		if (count_visible_from_top(grid, i) != constraints[i]
			|| count_visible_from_bottom(grid, i)
			!= constraints[4 + i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// pour gagner des lignes sinon plus de 25 :D
void	get_next_position(int row, int col, int *next_row, int *next_col)
{
	if (col == 3)
	{
		*next_row = row + 1;
		*next_col = 0;
	}
	else
	{
		*next_row = row;
		*next_col = col + 1;
	}
}

// brut force l'organisation des valeurs sur la map grace au backtracking
// repete l'operation tant que c'est faux
int	solve(int *constraints, int **grid, int row, int col)
{
	int	next_row;
	int	next_col;
	int	value;

	if (row == 4)
		return (check_constraints(constraints, grid));
	get_next_position(row, col, &next_row, &next_col);
	value = 1;
	while (value <= 4)
	{
		if (is_valid(grid, row, col, value))
		{
			grid[row][col] = value;
			if (solve(constraints, grid, next_row, next_col))
				return (1);
			grid[row][col] = 0;
		}
		value++;
	}
	return (0);
}

//retour d'erreur si l'application des valeurs 
//dans le terminal est autre que 16
int	parse(char *input, int *constraints)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] != '\0' && j < 16)
	{
		if (input[i] >= '1' && input[i] <= '4')
		{
			constraints[j] = input[i] - '0';
			j++;
		}
		else if (input[i] != ' ')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (j != 16 || input[i] != '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
