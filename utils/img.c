/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:34:47 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/21 17:34:47 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	img_error_exit(char *path)
{
	ft_putstr_fd("Error\nFailed to load image: ", 2);
	ft_putendl_fd((char *)path, 2);
	exit(1);
}

t_img	init_img(t_game *game, char *path)
{
	t_img	img;

	img.img_ptr = NULL;
	img.path = (char *)path;
	img.width = 0;
	img.height = 0;
	if (!game || !game->mlx || !path)
		img_error_exit(path);
	img.img_ptr = mlx_xpm_file_to_image(game->mlx, path,
			&img.width, &img.height);
	if (!img.img_ptr)
		img_error_exit(path);
	return (img);
}

void	set_img(t_game *game, t_img img, int x_pos, int y_pos)
{
	void	*mlx;
	void	*win;

	if (!game)
		print_error("Game Invaliable");
	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, img.img_ptr, x_pos * 64, y_pos * 64);
}

void	setting_img(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map.height)
	{
		width = 0;
		while (width < game->map.width)
		{
			if (game->map.map[height][width] == '1')
				set_img(game, game->wall, width, height);
			else if (game->map.map[height][width] == 'C')
				set_img(game, game->fish, width, height);
			else if (game->map.map[height][width] == 'P')
				set_img(game, game->box_cat_img, width, height);
			else if (game->map.map[height][width] == 'E')
				set_img(game, game->close_door, width, height);
			else
				set_img(game, game->tile, width, height);
			width++;
		}
		height++;
	}
}

void	destroy_images(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->cat_img.img_ptr)
		mlx_destroy_image(game->mlx, game->cat_img.img_ptr);
	if (game->box_cat_img.img_ptr)
		mlx_destroy_image(game->mlx, game->box_cat_img.img_ptr);
	if (game->close_door.img_ptr)
		mlx_destroy_image(game->mlx, game->close_door.img_ptr);
	if (game->open_door.img_ptr)
		mlx_destroy_image(game->mlx, game->open_door.img_ptr);
	if (game->fish.img_ptr)
		mlx_destroy_image(game->mlx, game->fish.img_ptr);
	if (game->tile.img_ptr)
		mlx_destroy_image(game->mlx, game->tile.img_ptr);
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx, game->wall.img_ptr);
}
