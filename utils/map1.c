/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:42:19 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/25 15:42:19 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_map_outline(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.map[0][i] != '1'
			|| game->map.map[game->map.height - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 1;
	while (i < game->map.height - 1)
	{
		if (game->map.map[i][0] != '1'
			|| game->map.map[i][game->map.width - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

static void	check_element_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->map.p_start_x = j;
				game->map.p_start_y = i;
				game->map.p_count++;
			}
			else if (game->map.map[i][j] == 'E')
				game->map.e_count++;
			else if (game->map.map[i][j] == 'C')
				game->map.c_count++;
			else if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1')
				print_error("Invalid map");
			j++;
		}
		i++;
	}
}

static int	check_map_element(t_game *game)
{
	check_element_count(game);
	if (game->map.p_count != 1 || game->map.e_count != 1
		|| game->map.c_count < 1)
		return (-1);
	return (0);
}

static int	check_path(t_game *game)
{
	int	i;
	int	height;

	height = game->map.height;
	game->map.dfs_map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!game->map.dfs_map)
		return (-1);
	i = 0;
	while (i < game->map.height)
	{
		game->map.dfs_map[i] = ft_strdup(game->map.map[i]);
		if (!game->map.dfs_map[i])
			return (free_rows(game->map.dfs_map, i), -1);
		i++;
	}
	game->map.dfs_map[i] = NULL;
	game->map.collected = 0;
	game->map.exit_found = 0;
	dfs_path(game, game->map.p_start_x, game->map.p_start_y);
	free_rows(game->map.dfs_map, game->map.height);
	if (game->map.collected == game->map.c_count && game->map.exit_found == 1)
		return (0);
	return (-1);
}

int	map_check(t_game *game)
{
	if (check_map_element(game) == -1)
		return (-1);
	else if (check_map_outline(game) == -1)
		return (-1);
	else if (check_path(game) == -1)
		return (-1);
	return (0);
}
