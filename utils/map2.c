/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:55:57 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/22 18:55:57 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map_rows(t_game *game, char *map_str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = (char *)malloc(sizeof(char) * (game->map.width + 1));
		if (!game->map.map[i])
		{
			free_map(game);
			free(map_str);
			print_error("Map row allocation failed");
		}
		j = 0;
		while (j < game->map.width)
		{
			game->map.map[i][j] = map_str[k++];
			j++;
		}
		game->map.map[i][game->map.width] = '\0';
		i++;
	}
}
