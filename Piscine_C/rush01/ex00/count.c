/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 09:28:25 by bozil             #+#    #+#             */
/*   Updated: 2024/09/22 12:09:23 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "./rush.h"

//prend en compte les caisses visible de la gauche
int	count_visible_from_left(int *row)
{
	int	visible;
	int	max_seen;
	int	i;

	visible = 0;
	max_seen = 0;
	i = 0;
	while (i < 4)
	{
		if (row[i] > max_seen)
		{
			max_seen = row[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

//prend en compte les caisses visible de la droite
int	count_visible_from_right(int *row)
{
	int	visible;
	int	max_seen;
	int	i;

	visible = 0;
	max_seen = 0;
	i = 3;
	while (i >= 0)
	{
		if (row[i] > max_seen)
		{
			max_seen = row[i];
			visible++;
		}
		i--;
	}
	return (visible);
}

//prend en compte les caisses visible d'en haut
int	count_visible_from_top(int **grid, int col)
{
	int	visible;
	int	max_seen;
	int	i;

	visible = 0;
	max_seen = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_seen)
		{
			max_seen = grid[i][col];
			visible++;
		}
		i++;
	}
	return (visible);
}

//prend en compte les caisses visible d'en bas
int	count_visible_from_bottom(int **grid, int col)
{
	int	visible;
	int	max_seen;
	int	i;

	visible = 0;
	max_seen = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max_seen)
		{
			max_seen = grid[i][col];
			visible++;
		}
		i--;
	}
	return (visible);
}
