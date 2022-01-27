#include "cub3D.h"

void	key_handler(int key, t_game *game)
{
	int ray_dist = 5;
	double x;
	double y;

	printf("***%d %d %f %f %c\n", game->map.height, game->map.width,
	game->player.posy, game->player.posx, game->map.size[(int)
	game->player.posy + 1][(int)game->player.posx]);
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
		x = game->player.posx + (cos(game->player.da));
		y = game->player.posy + (sin(game->player.da));
		printf("x%f y%f %d %d %f %d\n", x, y, (int)x, (int)y, game->player
		.posy, (int)game->player.posy);
//		if (game->map.size[(int)y][(int)x] == '1' && (int)x != game->map
//		.width- 1 && (int)y != game->map.height - 1 && (int)x != 1 && (int)y
//		!= 1)
//		{
//			printf("****%d\n", (int)x - (int)game->player.posx);
//			if ((int)x - (int)game->player.posx == 1 && (int)y -
//			(int)game->player.posy == 1)
//			{
//				printf("case1\n");
//				game->player.posx = (int)x;
//				game->player.posy = (int)y;
//			}
//			else if ((int)game->player.posx - (int)x == 1 && (int)game->player
//			.posy - (int)y == 1)
//			{
//				printf("case2\n");
//				game->player.posx = (int)game->player.posx;
//				game->player.posy = (int)game->player.posy;
//			}
//			else if ((int)(game->player.posx) == (int)x && (int)game->player
//			.posy
//			- (int)y == 1)
//			{
//				printf("case3\n");
//				game->player.posx = x;
//				game->player.posy = (int)game->player.posy;
//			}
//			else if ((int)(game->player.posx) == (int)x && (int)(y -
//			game->player
//			.posy) == 1)
//			{
//				printf("case4\n");
//				game->player.posx = x;
//				game->player.posy = (int)y;
//			}
//			else if ((int)(game->player.posy) == (int)y && (int)game->player
//			.posx
//			- (int)x == 1)
//			{
//				printf("case5\n");
//				game->player.posy = y;
//				game->player.posx = (int)game->player.posx;
//			}
//			else if ((int)(game->player.posy) == (int)y && (int)x - (int)
//			game->player
//			.posx == 1)
//			{
//				printf("case6\n");
//				game->player.posy = y;
//				game->player.posy = (int)x;
//			}
//			printf("hi *x=%f *y=%f posx%f posy %f%c\n", x, y,
//				   game->player.posx, game->player.posy, game->map
//			.size[
//					(int)y][
//					(int)x]);
//		}
//		else {
			printf("*x=%f *y=%f %c\n", x, y, game->map.size[(int)y][(int)x]);
			if (x < 1)
				game->player.posx = 1;
			else if (x > game->map.width - 1)
				game->player.posx = game->map.width - 1;
			else
				game->player.posx = x;
			if (y < 1)
				game->player.posy = 1;
			else if (y > game->map.height - 1)
				game->player.posy = game->map.height - 1;
			else
				game->player.posy = y;
			printf("*posx=%f *posy=%f\n", game->player.posx, game->player.posy);
	//	}

	}
	else if (key == KEY_DOWN)
	{
		x = game->player.posx - (cos(game->player.da));
		y = game->player.posy - (sin(game->player.da));
		printf("*x=%f *y=%f %d %d\n", x, y, game->map.width, game->map.height);
//		if (game->map.size[(int)y][(int)x] == '1' && (int)x != game->map
//		.width- 1 && (int)y != game->map.height - 1 && (int)x != 1 && (int)y
//		!= 1)
//		{
//			printf("****%d\n", (int)x - (int)game->player.posx);
//			if ((int)x - (int)game->player.posx == 1 && (int)y -
//														(int)game->player.posy == 1)
//			{
//				printf("case1\n");
//				game->player.posx = (int)x;
//				game->player.posy = (int)y;
//			}
//			else if ((int)game->player.posx - (int)x == 1 && (int)game->player
//					.posy - (int)y == 1)
//			{
//				printf("case2\n");
//				game->player.posx = (int)game->player.posx;
//				game->player.posy = (int)game->player.posy;
//			}
//			else if ((int)(game->player.posx) == (int)x && (int)game->player
//					.posy
//														   - (int)y == 1)
//			{
//				printf("case3\n");
//				game->player.posx = x;
//				game->player.posy = (int)game->player.posy;
//			}
//			else if ((int)(game->player.posx) == (int)x && (int)(y -
//																 game->player
//																		 .posy) == 1)
//			{
//				printf("case4\n");
//				game->player.posx = x;
//				game->player.posy = (int)y;
//			}
//			else if ((int)(game->player.posy) == (int)y && (int)game->player
//					.posx
//														   - (int)x == 1)
//			{
//				printf("case5\n");
//				game->player.posy = y;
//				game->player.posx = (int)game->player.posx;
//			}
//			else if ((int)(game->player.posy) == (int)y && (int)x - (int)
//					game->player
//							.posx == 1)
//			{
//				printf("case6\n");
//				game->player.posy = y;
//				game->player.posy = (int)x;
//			}
//			printf("hi *x=%f *y=%f posx%f posy %f%c\n", x, y,
//				   game->player.posx, game->player.posy, game->map
//						   .size[
//						   (int)y][
//						   (int)x]);
//		}
//		else {
			if (x < 1)
				game->player.posx = 1;
			else if (x > game->map.width - 1)
				game->player.posx = game->map.width - 1;
			else
				game->player.posx = x;
			if (y < 1)
				game->player.posy = 1;
			else if (y > game->map.height - 1)
				game->player.posy = game->map.height - 1;
			else
				game->player.posy = y;
//		}
		printf("*posx=%f *posy=%f\n", game->player.posx, game->player.posy);
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
	printf("bpp %d | linelen %d\n", game->image.bits_per_pixel, game->image.line_length);
	printf("dx==%f dy==%f da==%f\n", game->player.dx, game->player.dy, game->player.da);
	printf(CLRSCR);
}

int	key_pressed(int key, t_game *game)
{
	key_handler(key, game);
	return (0);
}