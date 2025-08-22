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
# define IMG_CAT	"../imgs/cat.xpm"
# define IMG_BOX_CAT "../imgs/box_cat.xpm"
# define CLOSE_DOOR	"../imgs/close_door.xpm"
# define OPEN_DOOR	"../imgs/open_door.xpm"
# define FISH	"../imgs/fish.xpm"
# define TILE	"../imgs/tile.xpm"
# define WALL	"../imgs/wall.xpm"

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
}	t_map;

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	c_count;
	int	move_count;
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

/*img*/
void	init_images(t_game *game);
void	destroy_images(t_game *game);

/*map*/
int		init_map(t_game *game);
void	make_map(t_game *game);
int		exit_game(t_game *game);

/*player*/
int		init_player(t_game *game);

/*game*/
int		init_game(t_game *game, char **argv);

/*utils*/
char	*dup_no_nl(const char *s);
char	*join_and_free(char *s1, const char *s2);

#endif