#include "cub3D.h"

void	key_down(t_game *game)
{
	double	x;
	double	y;
	double 	step;

	step = 0.3;
	x = game->player.posx;
	y = game->player.posy;
	while (game->map.size[(int)y][(int)x] != '1' && step > 0)
	{
		x = game->player.posx - cos(game->player.da) * step;
		y = game->player.posy + sin(game->player.da) * step;
		if (game->map.size[(int)y][(int)x] == '1')
		{
			step -= 0.1;
			x = game->player.posx + cos(game->player.da) * step;
			y = game->player.posy - sin(game->player.da) * step;
		}
		else
			break ;
	}
	move_player(game, (int) x, (int) y);
	game->player.posx = x;
	game->player.posy = y;
}

void	key_up(t_game *game)
{
	double	x;
	double	y;
	double 	step;

	step = 0.3;
	x = game->player.posx;
	y = game->player.posy;
	while (game->map.size[(int)y][(int)x] != '1' && step > 0)
	{
		x = game->player.posx + cos(game->player.da) * step;
		y = game->player.posy - sin(game->player.da) * step;
		if (game->map.size[(int)y][(int)x] == '1')
		{
			step -= 0.1;
			x = game->player.posx - cos(game->player.da) * step;
			y = game->player.posy + sin(game->player.da) * step;
		}
		else
			break ;
	}
	move_player(game, (int) x, (int) y);
	game->player.posx = x;
	game->player.posy = y;
}

void	key_right(t_game *game)
{
	game->player.da = game->player.da - 5 * PI / 180;
	if (game->player.da < 0)
		game->player.da += 2 * PI;
	game->player.dx = cos(game->player.da);
	game->player.dy = sin(game->player.da);
	if (game->map.size[(int)game->player.posy][(int)game->player.posx] != '1')
		move_player(game, (int) game->player.posx, (int)game->player.posy);
}

void	key_left(t_game *game)
{
	game->player.da = game->player.da + 5 * PI / 180;
	if (game->player.da > 2 * PI)
		game->player.da -= 2 * PI;
	game->player.dx = cos(game->player.da);
	game->player.dy = sin(game->player.da);
	if (game->map.size[(int)game->player.posy][(int)game->player.posx] != '1')
		move_player(game, (int) game->player.posx, (int)game->player.posy);
}

int	key_pressed(int key, t_game *game)
{
	if (key == KEY_ESC)
	{
		printf("You quit the game.\n");
		exit(0);
	}
	else if (key == KEY_UP)
		key_up(game);
	else if (key == KEY_DOWN)
		key_down(game);
	else if (key == KEY_LEFT)
		key_left(game);
	else if (key == KEY_RIGHT)
		key_right(game);
	to_draw(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img,
							0, 0);
	make_3d(game);
	return (0);
}

void	make_3d(t_game *game)
{
	int x;
	int hit;

	x = -1;
	while(++x < game->image.screen_w)
	{
		hit = 0;
		double dist_to_wall = 0;
		double ugol_obzora = PI / 3;
		double ray_a = x * ugol_obzora / game->image.screen_w;

		double ray_a_h = (game->player.da + ugol_obzora / 2) - ray_a;

		double dif_a = game->player.da - ray_a_h;
		if (dif_a > 2 * PI)
			dif_a -= 2 * PI;
		if (dif_a < 0)
			dif_a += 2 * PI;
		double y_dir = sin(ray_a_h);
		double x_dir = cos(ray_a_h);
		double y_dir_del;
		double x_dir_del;
		x_dir_del = 0;
		y_dir_del = 0;
		while (hit == 0 && dist_to_wall < 10)
		{
			x_dir_del = (game->player.posx + x_dir * dist_to_wall);
			y_dir_del = (game->player.posy - y_dir * dist_to_wall);
			if (game->map.size[(int) y_dir_del][(int) x_dir_del] == '1')
				hit = 1;
			else
				dist_to_wall += 0.01;
		}
		double size_wall = game->image.screen_h / dist_to_wall / cos(dif_a);
		if (size_wall > game->image.screen_h)
			size_wall = game->image.screen_h;
		double ceil = (game->image.screen_h - size_wall) / 2;
		double floor = (ceil + size_wall);
		double y = -1;
		while (++y < ceil) {
			my_mlx_pixel_put(&game->image, (int)x, (int)y, game->ident
			.c_rgb[0] <<	16 | game->ident.c_rgb[1]
					<< 8 | game->ident.c_rgb[2]);
//			mlx_pixel_put(game->vars.mlx, game->vars.win, x,
//						  (int) y,
//						  game->ident.c_rgb[0] << 16 | game->ident.c_rgb[1]
//								  << 8 | game->ident.c_rgb[2]);
		}
		//	y = ceil;
		while (y < floor)
		{
			my_mlx_pixel_put(&game->image, (int)x, (int)y, 255);
//			mlx_pixel_put(game->vars.mlx, game->vars.win, x, (int) y,
//						  255);
			y++;
		}
		while (y < game->image.screen_h)
		{
			my_mlx_pixel_put(&game->image, (int)x, (int)y, game->ident
			.f_rgb[0] <<	16 | game->ident.f_rgb[1]	<< 8 | game->ident.f_rgb[2]);
//			mlx_pixel_put(game->vars.mlx, game->vars.win, x, (int) y,
//						  game->ident.f_rgb[0] << 16 | game->ident.f_rgb[1]
//								  << 8 | game->ident.f_rgb[2]);
			y++;
		}
	}
}