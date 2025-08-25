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

static void	set_img(t_game *game, t_img img, int x_pos, int y_pos)
{
	void	*mlx;
	void	*win;

	if (!game)
		print_error("Game Invaliable");
	mlx = game->mlx;
	win = game->win;
	mlx_put_image_to_window(mlx, win, img.img_ptr, x_pos * 64, y_pos * 64);
}

static void	draw_door(t_game *game, int x, int y)
{
	if (game->map.c_count == 0)
		set_img(game, game->open_door, x, y);
	else
		set_img(game, game->close_door, x, y);
}

static void	draw_player(t_game *game, int x, int y)
{
	if (game->player.move_count == 0)
		set_img(game, game->box_cat_img, x, y);
	else
		set_img(game, game->cat_img, x, y);
}

static void	draw_cell(t_game *game, int x, int y)
{
	char	t;

	t = game->map.map[y][x];
	if (t == '1')
		set_img(game, game->wall, x, y);
	else if (t == '0')
		set_img(game, game->tile, x, y);	
	else if (t == 'C')
		set_img(game, game->fish, x, y);
	else if (t == 'P')
		draw_player(game, x, y);
	else if (t == 'E')
		draw_door(game, x, y);
}

void	setting_img(t_game *game)
{
	int	x;
	int	y;

	if (!game || !game->mlx || !game->win)
		return ;
	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			draw_cell(game, x, y);
			x++;
		}
		y++;
	}
}
