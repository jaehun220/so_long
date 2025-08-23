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

static t_img	init_img(t_game *game, char *path)
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

void	init_images(t_game *game)
{
	if (!game)
		return ;
	game->cat_img = init_img(game, IMG_CAT);
	game->box_cat_img = init_img(game, IMG_BOX_CAT);
	game->close_door = init_img(game, CLOSE_DOOR);
	game->open_door = init_img(game, OPEN_DOOR);
	game->fish = init_img(game, FISH);
	game->tile = init_img(game, TILE);
	game->wall = init_img(game, WALL);
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
