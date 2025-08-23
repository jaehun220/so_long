/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:58:16 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/23 16:58:16 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_map(t_game *game)
{
	if (!game)
		return (-1);
	game->map.map = NULL;
	game->map.c_count = 0;
	game->map.e_count = 0;
	game->map.p_count = 0;
	game->map.height = 0;
	game->map.width = 0;
	game->map.p_start_x = -1;
	game->map.p_start_y = -1;
	return (0);
}

int	init_images(t_game *game)
{
	if (!game)
		return (-1);
	game->cat_img = init_img(game, "imgs/cat.xpm");
	game->box_cat_img = init_img(game, "imgs/box_cat.xpm");
	game->close_door = init_img(game, "imgs/close_door.xpm");
	game->open_door = init_img(game, "imgs/open_door.xpm");
	game->fish = init_img(game, "imgs/fish.xpm");
	game->tile = init_img(game, "imgs/tile.xpm");
	game->wall = init_img(game, "imgs/wall.xpm");
	return (0);
}

int	init_player(t_game *game)
{
	if (!game)
		return (-1);
	game->player.c_count = 0;
	game->player.move_count = 0;
	game->player.pos_x = -1;
	game->player.pos_y = -1;
	return (0);
}

int	init_game(t_game *game, char **argv)
{
	if (!game || !argv || !argv[1])
		return (-1);
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (-1);
	if (init_map(game) != 0)
		return (close(game->fd), -1);
	if (init_player(game) != 0)
		return (close(game->fd), -1);
	if (init_images(game) != 0)
		return (close(game->fd), -1);
	game->win = NULL;
	return (0);
}
