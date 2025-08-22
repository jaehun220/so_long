/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:51:25 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/21 19:51:25 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

void	draw_map(t_game *game)
{
	if (!game)
		return ;
	
}
