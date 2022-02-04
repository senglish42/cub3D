#include "cub3D.h"

unsigned int wall(t_img *image, int j, int x)
{
	return (*(unsigned int *)(image->addr + (j * image->line_length + x * \
	image->bits_per_pixel / 8)));
}

unsigned int f_c(int rgb[3])
{
	return(rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	do_color(t_img *image, int x, int y, unsigned int color)
{
	my_mlx_pixel_put(image, x, y, color);
}

void	find_ratio(t_game *game, t_rend *rend)
{
	while (rend->hit == 0 && rend->dist_to_wall < 10)
	{
		rend->x_dir_del = (game->player.posx + rend->x_dir * rend->dist_to_wall);
		rend->y_dir_del = (game->player.posy - rend->y_dir * rend->dist_to_wall);
		if (game->map.size[(int) rend->y_dir_del][(int) rend->x_dir_del] == '1')
			rend->hit = 1;
		else
			rend->dist_to_wall += 0.01;
	}
	rend->size_wall = game->image.screen_h / rend->dist_to_wall / cos(rend->dif_a);
	if (rend->size_wall > game->image.screen_h)
		rend->size_wall = game->image.screen_h;
	rend->ceil = (game->image.screen_h - rend->size_wall) / 2;
	rend->floor = (rend->ceil + rend->size_wall);
}

double	check_rad(double angle)
{
	if (angle > 2 * PI)
		angle -= 2 * PI;
	else if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

void	init_rend(t_game *game, t_rend *rend, int x)
{
	rend->hit = 0;
	rend->dist_to_wall = 0;
	rend->ray_a = x * VA / game->image.screen_w;
	rend->ray_a_h = (game->player.da + VA / 2) - rend->ray_a;
	rend->dif_a = game->player.da - rend->ray_a_h;
	rend->dif_a = check_rad(rend->dif_a);
	rend->y_dir = sin(rend->ray_a_h);
	rend->x_dir = cos(rend->ray_a_h);
	rend->x_dir_del = 0;
	rend->y_dir_del = 0;
}



void	make_3d(t_game *game)
{
	t_rend	rend;
	int x;

	x = -1;
	while(++x < game->image.screen_w)
	{
		init_rend(game, &rend, x);
		find_ratio(game, &rend);
		double y = -1;
		while (++y < rend.ceil)
			do_color(&game->image, (int)x, (int)y, f_c(game->ident.c_rgb));
		double j;
		j = 0;
		int a;
		a = game->image.screen_h - (int)y;
		while (y < rend.floor)
		{
//			if (j == 0)
//				printf("%d %d\n", x + 1, (int)y);
//				printf("%d %d\n", (int)((game->image.screen_h + 1) /
//						(int)y), (int)
//						(game->image
//								 .screen_w / (x + 1)));
//				printf("%c\n", game->map.size[((game->image.screen_h + 1) /
//						(int)y)][(int)
//						(game->image
//								 .screen_w / x)]);
			if (rend.ray_a_h >= PI / 4 && rend.ray_a_h < 3 * PI / 4)
			{
				do_color(&game->image, (int)x, (int)y++, \
				wall(&game->path[0],(int)j,(int)x));
				j += (double) game->path[0].screen_h / (double) rend.size_wall;
			}
			else if (rend.ray_a_h >= 3 * PI / 4 && rend.ray_a_h < 5 * PI / 4)
			{
				do_color(&game->image, (int)x, (int)y++, \
				wall(&game->path[2],(int)j,(int)x));
				j += (double) game->path[2].screen_h / (double) rend.size_wall;
			}
			else if (rend.ray_a_h >= 5 * PI / 4 && rend.ray_a_h < 7 * PI / 4)
			{
				do_color(&game->image, (int)x, (int)y++, \
				wall(&game->path[1],(int)j,(int)x));
				j += (double) game->path[1].screen_h / (double) rend.size_wall;
			}
			else
			{
				do_color(&game->image, (int)x, (int)y++, \
				wall(&game->path[3],(int)j,(int)x));
				j += (double) game->path[3].screen_h / (double) rend.size_wall;
			}
		}
		while (y < game->image.screen_h)
			do_color(&game->image, (int)x, (int)y++, f_c(game->ident.f_rgb));
	}
}
