/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:55:59 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/21 19:55:59 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static char	*path_maker(char *filename)
{	
	char	*path;
	int		len;
	int		i;

	len = ft_strlen(filename);
	path = (char *)malloc(sizeof(char) * (len + 5));
	if (!path)
		return (NULL);
	path[0] = 'm';
	path[1] = 'a';
	path[2] = 'p';
	path[3] = '/';
	i = 0;
	while (i < len)
	{
		path[4 + i] = filename[i];
		i++;
	}
	path[4 + i] = '\0';
	return (path);
}

int	init_game(t_game *game, char **argv)
{
	char	*path;

	if (!game)
		return (-1);
	path = path_maker(argv[1]);
	if (!path)
		return (-1);
	game->fd = open(path, O_RDONLY);
	free(path);
	if (game->fd <= 0)
		return (-1);
	ft_bzero(game, sizeof(t_game));
	init_map(game);
	init_player(game);
	init_images(game);
	game->mlx = mlx_init();
	game->win = NULL;
	return (0);
}
