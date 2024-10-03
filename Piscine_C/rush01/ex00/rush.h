/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 10:08:56 by bozil             #+#    #+#             */
/*   Updated: 2024/09/22 13:33:59 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

//redirige les divers dossier en .c pour utiliser leurs fonctions
void	print_grid(int **grid);
int		is_valid(int **grid, int row, int col, int value);
int		count_visible_from_left(int *row);
int		count_visible_from_right(int *row);
int		count_visible_from_top(int **grid, int col);
int		count_visible_from_bottom(int **grid, int col);
int		check_constraints(int *constraint, int **grid);
int		solve(int *constraints, int **grid, int row, int col);
int		parse(char *input, int *constraint);
int		main(int argc, char **argv);

#endif
