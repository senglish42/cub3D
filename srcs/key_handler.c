#include "cub3D.h"

void	key_handler(int key, t_game *game)
{
	int ray_dist = 5;

	if (key == KEY_ESC)
	{
		free(game);
		exit(0);
	}
	if (key == KEY_RIGHT)
	{
		game->player.da += 0.1;
		if (game->player.da > 2 * PI)
			game->player.da -= (2 * PI);
		game->player.dx = cos(game->player.da) * ray_dist;
		game->player.dy = sin(game->player.da) * ray_dist;
	}
	else if (key == KEY_LEFT)
	{
		game->player.da -= 0.1;
		if (game->player.da < 0)
			game->player.da += 2 * PI;
		game->player.dx = cos(game->player.da) * ray_dist;
		game->player.dy = sin(game->player.da) * ray_dist;
	}
	else if (key == KEY_UP)
	{
		game->player.posx += (cos(game->player.da)); // rayDirX
		game->player.posy += (sin(game->player.da)); // rayDirY
	}
	else if (key == KEY_DOWN)
	{
		game->player.posx -= (cos(game->player.da));
		game->player.posy -= (sin(game->player.da));
	}
	
	t_vec	hor;
	t_vec	ver;
	t_vec	min;

	//double hor_x = 0;
	//double hor_y = 0;
	//double ver_x = 0;
	//double ver_y = 0;

	find_intersection_horizontal(game, &hor.x, &hor.y); // GREEN
	find_intersection_vertical(game, &ver.x, &ver.y);	// YELLOw 
	find_min_vec(hor, ver, &min);

	my_clear_window(game);
	draw_minimap(game);
	draw_miniplayer(game, hor.x, hor.y);
	draw_line(game, game->player.posx * 50, game->player.posy * 50, 
				min.x * 50, 
				min.y * 50, GREEN);
	draw_scaled_point(game, min.x, min.y, GREEN);
	/*
	draw_line(game, game->player.posx * 50, game->player.posy * 50, 
				ver.x * 50, 
				ver.y * 50, YELLOW);
	draw_scaled_point(game, ver.x, ver.y, YELLOW); */
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img, 0,
							0);
	
	//draw_debug_map(game);
	printf("player pos: %f %f\n", game->player.posx, game->player.posy);
	printf("bpp %d | linelen %d\n", game->image.bits_per_pixel, game->image
	.line_length);
	printf("dx==%f dy==%f da==%f\n", game->player.dx, game->player.dy, game->player.da);
	printf(CLRSCR);
}

int	key_pressed(int key, t_game *game)
{
	key_handler(key, game);
	return (0);
}