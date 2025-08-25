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

static void	print_move(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->player.move_count, 1);
	ft_putstr_fd("\n", 1);
}

int	is_walkable(int x, int y, t_game *g)
{
	char	t;

	if (x < 0 || y < 0 || x >= g->map.width || y >= g->map.height)
		return (0);
	t = g->map.map[y][x];
	return (t != '1');
}

static void	restore_prev_tile(t_game *game)
{
	int	x;
	int	y;

	x = game->player.pos_x;
	y = game->player.pos_y;
	if (game->player.on_exit)
		game->map.map[y][x] = 'E';
	else
		game->map.map[y][x] = '0';
}

static void	apply_next_tile(t_game *g, int x, int y, char next)
{
	if (next == 'E')
	{
		g->map.map[y][x] = 'P';
		g->player.on_exit = 1;
	}
	else
	{
		g->map.map[y][x] = 'P';
		g->player.on_exit = 0;
	}
}

void	move_player(int x, int y, t_game *g)
{
	char	next;

	next = g->map.map[y][x];
	if (next == 'C')
	{
		g->map.c_count--;
		g->map.map[y][x] = '0';
		next = '0';
	}
	restore_prev_tile(g);
	if (next == 'E' && g->map.c_count == 0)
	{
		g->player.pos_x = x;
		g->player.pos_y = y;
		g->player.move_count++;
		print_move(g);
		exit_game(g);
		return ;
	}
	apply_next_tile(g, x, y, next);
	g->player.pos_x = x;
	g->player.pos_y = y;
	g->player.move_count++;
	print_move(g);
	setting_img(g);
}
