#include <stdio.h>
#include "../includes/so_long.h"

int	draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->c, loc->x, loc->y);
	return (0);
}

int	main(void)
{
	void *mlx;
	void *win;
	void *img;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./images/tile.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./images/cat.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./images/fish.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./images/open_door.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "./images/close_door.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 128, 64);
	mlx_put_image_to_window(mlx, win, img5, 0, 64);
	mlx_put_image_to_window(mlx, win, img6, 64, 64);
	mlx_loop(mlx);
}