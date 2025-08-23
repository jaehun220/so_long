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

#include "../includes/so_long.h"

static char	*join_and_free(char *s1, const char *s2)
{
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (s1);
	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

static int	consume_line(t_game *g, const char *raw, char **acc)
{
	char	*ln;
	int		w;

	ln = dup_no_nl(raw);
	if (!ln)
		return (-1);
	w = (int)ft_strlen(ln);
	if (g->map.width < 0)
		g->map.width = w;
	else if (w != g->map.width)
		return (free(ln), -1);
	*acc = join_and_free(*acc, ln);
	free(ln);
	if (!*acc)
		return (-1);
	g->map.height++;
	return (0);
}

char	*map_read(t_game *game)
{
	char	*raw;
	char	*acc;

	if (!game || game->fd < 0)
		return (NULL);
	game->map.width = -1;
	game->map.height = 0;
	acc = NULL;
	raw = get_next_line(game->fd);
	while (raw)
	{
		if (consume_line(game, raw, &acc) != 0)
			return (free(raw), free(acc), NULL);
		free(raw);
		raw = get_next_line(game->fd);
	}
	if (game->map.width <= 0 || game->map.height <= 0)
		return (free(acc), NULL);
	if (ft_strlen(acc) != (game->map.width * game->map.height))
		return (free(acc), NULL);
	return (acc);
}

void	make_map(t_game *g, char *s)
{
	size_t	off;
	int		y;

	if (!g || !s || g->map.width <= 0 || g->map.height <= 0)
		return ;
	g->map.map = (char **)malloc(sizeof(char *) * (g->map.height + 1));
	if (!g->map.map)
		return ;
	y = 0;
	off = 0;
	while (y < g->map.height)
	{
		g->map.map[y] = (char *)malloc((size_t)g->map.width + 1);
		if (!g->map.map[y])
			return ((void)free_rows(g->map.map, y), free(s));
		ft_memcpy(g->map.map[y], s + off, (size_t)g->map.width);
		g->map.map[y][g->map.width] = '\0';
		off += (size_t)g->map.width;
		y++;
	}
	g->map.map[y] = NULL;
	free(s);
}
