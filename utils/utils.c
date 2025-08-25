/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:48:41 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/22 15:48:41 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*free_rows(char **rows, int until)
{
	int	i;

	if (!rows)
		return (NULL);
	i = 0;
	while (i < until)
		free(rows[i++]);
	free(rows);
	return (NULL);
}

void	print_error(char *str)
{
	perror(str);
	exit(0);
}

char	*dup_no_nl(const char *s)
{
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r'))
		len--;
	return (ft_substr(s, 0, (unsigned int)len));
}

char	*join_and_free(char *s1, const char *s2)
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

void	dfs_path(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height
		|| game->map.dfs_map[y][x] == '1' || game->map.dfs_map[y][x] == 'V')
		return ;
	if (game->map.dfs_map[y][x] == 'C')
		game->map.collected++;
	if (game->map.dfs_map[y][x] == 'E')
		game->map.exit_found = 1;
	game->map.dfs_map[y][x] = 'V';
	dfs_path(game, x + 1, y);
	dfs_path(game, x - 1, y);
	dfs_path(game, x, y + 1);
	dfs_path(game, x, y - 1);
}
