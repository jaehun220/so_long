/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehlee <jaehlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:31:03 by jaehlee           #+#    #+#             */
/*   Updated: 2025/08/18 23:31:03 by jaehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define GREEN		0xA9C2A9
# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_DOWN	65364
# define KEY_RIGHT	65363
# define PRESS_EXIT	17
# define TILE_SIZE 64

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		p_start_x;
	int		p_start_y;
	int		c_count;
	int		e_count;
	int		p_count;
	char	**dfs_map;
	int		collected;
	int		exit_found;
}	t_map;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	c_count;
	int	move_count;
	int	on_exit;
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	size_t		fd;
	t_map		map;
	t_player	player;
	t_img		wall;
	t_img		tile;
	t_img		fish;
	t_img		open_door;
	t_img		close_door;
	t_img		cat_img;
	t_img		box_cat_img;
}	t_game;	

int		key_press(int keycode, t_game *game);

/*utils*/
char	*dup_no_nl(const char *s);
void	*free_rows(char **rows, int until);
void	print_error(char *str);
void	dfs_path(t_game *game, int x, int y);

/*img*/
void	destroy_images(t_game *game);
t_img	init_img(t_game *game, char *path);
int		init_images(t_game *game);
void	setting_img(t_game *game);

/*map*/
void	fill_map_rows(t_game *game, char *map_str);
int		init_map(t_game *game);
void	make_map(t_game *g, char *s);
char	*map_read(t_game *game);
int		map_check(t_game *game);

/*move*/
void	handle_move(int keycode, t_game *game);
int		is_walkable(int x, int y, t_game *g);
void	move_player(int x, int y, t_game *g);

/*player*/
int		init_player(t_game *game);

/*game*/
int		init_game(t_game *game, char **argv);
void	make_win(t_game *game);
int		exit_game(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);

#endif