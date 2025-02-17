/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlarbi <rlarbi@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:26:56 by rlarbi            #+#    #+#             */
/*   Updated: 2025/02/17 11:27:11 by rlarbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <unistd.h>

void	*mlx_ptr;
void	*win_ptr;
void	*img_ptr;
int width, height;

int	key_hook(int keycode, void *param)
{
	(void)param;          // Empêche le warning "unused parameter"
	if (keycode == 65307) // ESC
		mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}

int	main(void)
{
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "So Long");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./textures/steve.xpm", &width,
			&height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	mlx_key_hook(win_ptr, key_hook, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
