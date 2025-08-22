/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:50:40 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/19 00:50:40 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	handle_move(keycode, game);
	return (0);
}

int	is_valid_move(int x, int y, t_game *game)
{
	char	next_tile;

	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (0);
	next_tile = game->map.map[y][x];
	if (next_tile == '1')
		return (0);
	return (1);
}

void	handle_move(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.pos_x;
	new_y = game->player.pos_y;
	if (keycode == KEY_W || keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_x++;
	if (is_valid_move(new_x, new_y, game))
		move_player(new_x, new_y, game);
}

void	move_player(int x, int y, t_game *game)
{
	char	next_tile;

	next_tile = game->map.map[y][x];
	if (next_tile == 'C')
	{
		game->player.c_count++;
		game->map.map[y][x] = 0;
	}
	game->player.pos_x = x;
	game->player.pos_y = y;
	game->player.move_count++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->player.move_count, 1);
	ft_putstr_fd("\n", 1);
	draw_map(game);
}

int	exit_game(t_game *game)
{
	if (game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
