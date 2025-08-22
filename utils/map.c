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

static void	read_lines_and_join(t_game *game, char *line, char **map_str)
{
	while (line)
	{
		game->map.height++;
		*map_str = join_and_free(*map_str, line);
		free(line);
		line = get_next_line(game->fd);
	}
}

static char	*read_and_join_lines(t_game *game, char *map_str)
{
	char	*line;
	int		current_width;

	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		current_width = ft_strlen(line);
		if (current_width > 0 && line[current_width - 1] == '\n')
			current_width--;
		if (game->map.width != current_width)
		{
			free(map_str);
			free(line);
			close(game->fd);
			return (NULL);
		}
		map_str = join_and_free(map_str, line);
		free(line);
		game->map.height++;
	}
	return (map_str);
}

char	*map_read(t_game *game)
{
	char	*line;
	char	*map_str;

	line = get_next_line(game->fd);
	if (!line)
	{
		close(game->fd);
		return (NULL);
	}
	game->map.width = ft_strlen(line);
	if (game->map.width > 0 && line[game->map.width - 1] == '\n')
		game->map.width--;
	map_str = dup_no_nl(line);
	free(line);
	game->map.height = 1;
	map_str = read_and_join_lines(game, map_str);
	close(game->fd);
	return (map_str);
}

void	make_map(t_game *game, char *map_str)
{
	if (!map_str)
		return ;
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.map)
	{
		free(map_str);
		print_error("Map allocation failed");
	}
	game->map.map[game->map.height] = NULL;
	fill_map_rows(game, map_str);
	free(map_str);
}
