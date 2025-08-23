/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:59:34 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/19 20:59:34 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		print_error("Malloc Error");
	if (init_game(game, argv) == -1)
	{
		free(game);
		print_error("Init Error\n");
	}
	make_map(game, map_read(game));
	make_win(game);
	setting_img(game);
	mlx_loop(game->mlx);
	return (0);
}
