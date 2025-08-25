/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:55:59 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/21 19:55:59 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	make_win(t_game *game)
{
	int	width;
	int	height;

	width = game->map.width * TILE_SIZE;
	height = game->map.height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	handle_move(keycode, game);
	return (0);
}

int	exit_game(t_game *game)
{
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	handle_move(int keycode, t_game *g)
{
	int	nx;
	int	ny;

	nx = g->player.pos_x;
	ny = g->player.pos_y;
	if (keycode == KEY_W || keycode == KEY_UP)
		ny--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		ny++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		nx--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		nx++;
	if (is_walkable(nx, ny, g))
		move_player(nx, ny, g);
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