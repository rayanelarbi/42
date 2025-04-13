/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:40:22 by rlarbi            #+#    #+#             */
/*   Updated: 2025/04/13 19:41:01 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TILE_SIZE 64

char	**map;
int		map_width = 0, map_height = 0;
int player_x, player_y;
int		collectibles = 0;
int		move_count = 0;
int		door_sound_played = 0;

void	play_sound(const char *filepath)
{
	char	command[256];

	snprintf(command, sizeof(command), "aplay %s &", filepath); // Utilisation de `aplay` pour Linux
	system(command);
}

void	get_map_size(const char *filename)
{
	FILE	*file;
	char	ch;

	int width, height;
	width = 0, height = 0;
	file = fopen(filename, "r");
	if (!file)
	{
		perror("Erreur ouverture fichier");
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
		{
			if (width > map_width)
				map_width = width;
			width = 0;
			height++;
		}
		else
			width++;
	}
	map_height = height;
	fclose(file);
}

void	read_map_from_file(const char *filename)
{
	FILE	*file;

	file = fopen(filename, "r");
	if (!file)
	{
		perror("Erreur ouverture fichier");
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(char *) * map_height);
	for (int y = 0; y < map_height; y++)
	{
		map[y] = malloc(sizeof(char) * (map_width + 1));
		fgets(map[y], map_width + 2, file);
		for (int x = 0; x < map_width; x++)
		{
			if (map[y][x] == 'P')
			{
				player_x = x;
				player_y = y;
			}
			else if (map[y][x] == 'C')
				collectibles++;
		}
	}
	fclose(file);
}

void *mlx_ptr, *win_ptr, *wall_img, *floor_img, *player_img, *exit_img,
	*collectible_img, *door_open_img;

int width, height;

void	draw_map(void)
{
	char	move_text[50];
	void	*img;
	void	*current_exit_img;

	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			img = (map[y][x] == '1') ? wall_img : floor_img;
			mlx_put_image_to_window(mlx_ptr, win_ptr, img, x * TILE_SIZE, y
				* TILE_SIZE);
			if (map[y][x] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, collectible_img, x
					* TILE_SIZE, y * TILE_SIZE);
			else if (map[y][x] == 'E')
			{
				current_exit_img = (collectibles == 0) ? door_open_img : exit_img;
				mlx_put_image_to_window(mlx_ptr, win_ptr, current_exit_img, x
					* TILE_SIZE, y * TILE_SIZE);
			}
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, player_img, player_x * TILE_SIZE,
		player_y * TILE_SIZE);
	snprintf(move_text, sizeof(move_text), "Step : %d", move_count);
	mlx_string_put(mlx_ptr, win_ptr, 50, 30, 0xFFFFFF, move_text);
}

int	key_hook(int keycode, void *param)
{
	int	new_x = player_x, new_y = player_y;

	(void)param;

	if (keycode == 65307) // Échap
		exit(0);
	if (keycode == 119 || keycode == 65362) // W ou Flèche haut
		new_y--;
	if (keycode == 97 || keycode == 65361) // A ou Flèche gauche
		new_x--;
	if (keycode == 115 || keycode == 65364) // S ou Flèche bas
		new_y++;
	if (keycode == 100 || keycode == 65363) // D ou Flèche droite
		new_x++;
	if (new_y >= 0 && new_x >= 0 && new_y < map_height && new_x < map_width
		&& map[new_y][new_x] != '1')
	{
		if (map[new_y][new_x] == 'C')
		{
			collectibles--;
			map[new_y][new_x] = '0';
			play_sound("./sounds/orb.wav");
			if (collectibles == 0 && !door_sound_played)
			{
				play_sound("./sounds/open_door.wav");
				door_sound_played = 1;
			}
		}
		if (map[new_y][new_x] == 'E' && collectibles == 0)
		{
			printf("Félicitations, vous avez gagné !\n");
			exit(0);
		}
		player_x = new_x;
		player_y = new_y;
		move_count++;
		printf("Step : %d\n", move_count);
		draw_map();
	}
	return (0);
}

int	close_window(void)
{
	exit(0);
}

void	load_textures_for_map(void)
{
	// Chargement des textures fixes pour toutes les cartes
	wall_img = mlx_xpm_file_to_image(mlx_ptr, "./textures/deepslate_tiles.xpm",
			&width, &height);
	floor_img = mlx_xpm_file_to_image(mlx_ptr, "./textures/stone_bricks.xpm",
			&width, &height);
	player_img = mlx_xpm_file_to_image(mlx_ptr, "./textures/steve.xpm", &width,
			&height);
	exit_img = mlx_xpm_file_to_image(mlx_ptr,
			"./textures/trial_spawner_top_active_ominous.xpm", &width, &height);
	collectible_img = mlx_xpm_file_to_image(mlx_ptr,
			"./textures/stone_bricks_w_diams.xpm", &width, &height);
	door_open_img = mlx_xpm_file_to_image(mlx_ptr,
			"./textures/trial_spawner_top_ejecting_reward_ominous.xpm", &width,
			&height); // Porte ouverte
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	get_map_size(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, map_width * TILE_SIZE, map_height
			* TILE_SIZE, "So Long");
	load_textures_for_map(); // Chargement des textures fixes
	read_map_from_file(argv[1]);
	draw_map();
	mlx_key_hook(win_ptr, key_hook, NULL);
	mlx_hook(win_ptr, 33, 1L << 17, close_window, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
