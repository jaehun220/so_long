/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:31:17 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/21 15:31:17 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

void	map_read(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	
}

void	make_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
}
