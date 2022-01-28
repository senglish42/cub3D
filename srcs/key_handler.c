#include "cub3D.h"

void	to_draw(int key, t_game *game)
{
	t_vec	hor;
	t_vec	ver;
	t_vec	min;

//	double hor_x = 0;
//	double hor_y = 0;
//	double ver_x = 0;
//	double ver_y = 0;
	(void)key;
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
}

void	key_handler(int key, t_game *game)
{
//	int ray_dist = 5;
//	double x;
//	double y;

//	printf("***%d %d %f %f %c\n", game->map.height, game->map.width,
//	game->player.posy, game->player.posx, game->map.size[(int)
//	game->player.posy + 1][(int)game->player.posx]);
//	if (key == KEY_ESC)
//	{
//		free(game);
//		exit(0);
//	}
//	if (key == KEY_RIGHT)
//	{
//		game->player.da += 0.05;
//		if (game->player.da > 2 * PI)
//			game->player.da -= (2 * PI);
//		game->player.dx = cos(game->player.da) * ray_dist;
//		game->player.dy = sin(game->player.da) * ray_dist;
//	}
//	else if (key == KEY_LEFT)
//	{
//		game->player.da -= 0.05;
//		if (game->player.da < 0)
//			game->player.da += (2 * PI);
//		game->player.dx = cos(game->player.da) * ray_dist;
//		game->player.dy = sin(game->player.da) * ray_dist;
//		to_draw(key, game);
//	}
//	else if (key == KEY_UP)
//	{
//		x = game->player.posx + (cos(game->player.da));
//		y = game->player.posy + (sin(game->player.da));
//		printf("x%f y%f %d %d %f %d\n", x, y, (int)x, (int)y, game->player
//		.posy, (int)game->player.posy);
////		if (game->map.size[(int)y][(int)x] == '1' && (int)x != game->map
////		.width- 1 && (int)y != game->map.height - 1 && (int)x != 1 && (int)y
////		!= 1)
////		{
////			printf("****%d\n", (int)x - (int)game->player.posx);
////			if ((int)x - (int)game->player.posx == 1 && (int)y -
////			(int)game->player.posy == 1)
////			{
////				printf("case1\n");
////				game->player.posx = (int)x;
////				game->player.posy = (int)y;
////			}
////			else if ((int)game->player.posx - (int)x == 1 && (int)game->player
////			.posy - (int)y == 1)
////			{
////				printf("case2\n");
////				game->player.posx = (int)game->player.posx;
////				game->player.posy = (int)game->player.posy;
////			}
////			else if ((int)(game->player.posx) == (int)x && (int)game->player
////			.posy
////			- (int)y == 1)
////			{
////				printf("case3\n");
////				game->player.posx = x;
////				game->player.posy = (int)game->player.posy;
////			}
////			else if ((int)(game->player.posx) == (int)x && (int)(y -
////			game->player
////			.posy) == 1)
////			{
////				printf("case4\n");
////				game->player.posx = x;
////				game->player.posy = (int)y;
////			}
////			else if ((int)(game->player.posy) == (int)y && (int)game->player
////			.posx
////			- (int)x == 1)
////			{
////				printf("case5\n");
////				game->player.posy = y;
////				game->player.posx = (int)game->player.posx;
////			}
////			else if ((int)(game->player.posy) == (int)y && (int)x - (int)
////			game->player
////			.posx == 1)
////			{
////				printf("case6\n");
////				game->player.posy = y;
////				game->player.posy = (int)x;
////			}
////			printf("hi *x=%f *y=%f posx%f posy %f%c\n", x, y,
////				   game->player.posx, game->player.posy, game->map
////			.size[
////					(int)y][
////					(int)x]);
////		}
////		else {d
//			printf("*x=%f *y=%f %c\n", x, y, game->map.size[(int)y][(int)x]);
//			if (x < 1)
//				game->player.posx = 1;
//			else if (x > game->map.width - 1)
//				game->player.posx = game->map.width - 1;
//			else
//				game->player.posx = x;
//			if (y < 1)
//				game->player.posy = 1;
//			else if (y > game->map.height - 1)
//				game->player.posy = game->map.height - 1;
//			else
//				game->player.posy = y;
//			printf("*posx=%f *posy=%f\n", game->player.posx, game->player.posy);
//	//	}
//
//	}
//	else if (key == KEY_DOWN)
//	{
//		x = game->player.posx - (cos(game->player.da));
//		y = game->player.posy - (sin(game->player.da));
//		printf("*x=%f *y=%f %d %d\n", x, y, game->map.width, game->map.height);
////		if (game->map.size[(int)y][(int)x] == '1' && (int)x != game->map
////		.width- 1 && (int)y != game->map.height - 1 && (int)x != 1 && (int)y
////		!= 1)
////		{
////			printf("****%d\n", (int)x - (int)game->player.posx);
////			if ((int)x - (int)game->player.posx == 1 && (int)y -
////														(int)game->player.posy == 1)
////			{
////				printf("case1\n");
////				game->player.posx = (int)x;
////				game->player.posy = (int)y;
////			}
////			else if ((int)game->player.posx - (int)x == 1 && (int)game->player
////					.posy - (int)y == 1)
////			{
////				printf("case2\n");
////				game->player.posx = (int)game->player.posx;
////				game->player.posy = (int)game->player.posy;
////			}
////			else if ((int)(game->player.posx) == (int)x && (int)game->player
////					.posy
////														   - (int)y == 1)
////			{
////				printf("case3\n");
////				game->player.posx = x;
////				game->player.posy = (int)game->player.posy;
////			}
////			else if ((int)(game->player.posx) == (int)x && (int)(y -
////																 game->player
////																		 .posy) == 1)
////			{
////				printf("case4\n");
////				game->player.posx = x;
////				game->player.posy = (int)y;
////			}
////			else if ((int)(game->player.posy) == (int)y && (int)game->player
////					.posx
////														   - (int)x == 1)
////			{
////				printf("case5\n");
////				game->player.posy = y;
////				game->player.posx = (int)game->player.posx;
////			}
////			else if ((int)(game->player.posy) == (int)y && (int)x - (int)
////					game->player
////							.posx == 1)
////			{
////				printf("case6\n");
////				game->player.posy = y;
////				game->player.posy = (int)x;
////			}
////			printf("hi *x=%f *y=%f posx%f posy %f%c\n", x, y,
////				   game->player.posx, game->player.posy, game->map
////						   .size[
////						   (int)y][
////						   (int)x]);
////		}
////		else {
//			if (x < 1)
//				game->player.posx = 1;
//			else if (x > game->map.width - 1)
//				game->player.posx = game->map.width - 1;
//			else
//				game->player.posx = x;
//			if (y < 1)
//				game->player.posy = 1;
//			else if (y > game->map.height - 1)
//				game->player.posy = game->map.height - 1;
//			else
//				game->player.posy = y;
////		}
//		printf("*posx=%f *posy=%f\n", game->player.posx, game->player.posy);
//	}

//	printf("& %f\n", game->player.da);
//	my_clear_window(game);
	mlx_clear_window(game->vars.mlx, game->vars.win);
	if (key == KEY_UP)
	{
//		printf("up\n");
		game->player.posx += cos(game->player.da) * 0.1;
		game->player.posy += sin(game->player.da) * 0.1;
		printf("x %f y %f\n", game->player.posx, game->player.posy);
//		game->player.posy -= 1;
	}
	else if (key == KEY_DOWN)
	{
//		printf("down\n");

		game->player.posx -= cos(game->player.da) * 0.1;
		game->player.posy -= sin(game->player.da) * 0.1;
//		game->player.posy += 1;
	}
	else if (key == KEY_LEFT)
	{
//		printf("left\n");
		game->player.da += 0.1;
		if (game->player.da < 0)
			game->player.da += 2 * PI;
//		game->player.dx = cos(game->player.da);
//		game->player.dy = sin(game->player.da);
//		game->player.posx -= 1;
	}
	else if (key == KEY_RIGHT)
	{
//		printf("right\n");
		game->player.da -= 0.1;
		if (game->player.da > 2 * PI)
			game->player.da -= 2 * PI;
//		game->player.dx = cos(game->player.da);
//		game->player.dy = sin(game->player.da);
//		game->player.posx += 1;
	}
	else if (key == KEY_ESC)
		exit (0);
//	printf("da %f\n", game->player.da);
//	to_draw(key, game);
//	double aTan;
//	int 	size;
//	int 	count;
//
//	count = 0;
//	size = game->map.width * game->map.height;
//	game->ray.ra = game->player.da;
//	game->ray.r = 0;
//	printf("ray_r %d\n", game->ray.r);
	int x = 0;
	while(x < game->image.screen_w)
	{
		int hit = 0;
		double dist_to_wall = 0;
		double ugol_obzora = PI / 2;
		double ray_a = x * ugol_obzora / game->image.screen_w;
		double ray_a_h = (game->player.da + ugol_obzora / 2) - ray_a;
		double y_dir = sin(ray_a_h);
		double x_dir = cos(ray_a_h);
		double y_dir_del;
		double x_dir_del;
//		int y_h = game->player.posy;
//		int y_x =;
//		printf("%d ", game->image.screen_w);
		while(hit == 0 && dist_to_wall < 10)
		{
			x_dir_del = game->player.posx + x_dir * dist_to_wall;
			y_dir_del = game->player.posy + y_dir * dist_to_wall;
			if (game->map.size[(int)y_dir_del][(int)x_dir_del] == '1')
				hit = 1;
			dist_to_wall += 0.01;
		}
//		printf("%f ", dist_to_wall);
		int size_wall = game->image.screen_h/dist_to_wall;
		if (size_wall > game->image.screen_h)
			size_wall = game->image.screen_h;
		int ceil = (game->image.screen_h - size_wall) / 2;
		int floor = ceil + size_wall;
		int y = ceil;
		while(y < floor)
		{
			mlx_pixel_put(game->vars.mlx, game->vars.win, x, y, 26506);
			y++;
		}
		x++;
	}
//	while (game->ray.r < 1)
//	{
//		aTan = -1 / tan(game->ray.ra);
//		if (game->ray.ra > PI)
//		{
//			game->ray.ry = (((int) game->player.dy >> 6) << 6) - 0.0001;
//			game->ray.rx = (game->player.dy - game->ray.ry) * aTan + game->player.dx;
//			game->ray.yo = -size;
//			game->ray.xo = -game->ray.yo * aTan;
//		}
//		if (game->ray.ra < PI)
//		{
//			game->ray.ry = (((int) game->player.dy >> 6) << 6) + size;
//			game->ray.rx = (game->player.dy - game->ray.ry) * aTan + game->player.dx;
//			game->ray.yo = size;
//			game->ray.xo = -game->ray.yo * aTan;
//		}
//		if (game->ray.ra == 0 || game->ray.ra == PI)
//		{
//			game->ray.rx = game->player.dx;
//			game->ray.ry = game->player.dy;
//			game->ray.dof = game->map.width;
//		}
//		printf("ray rx %f ry %f\n", game->ray.rx, game->ray.ry);
//		while (game->ray.dof < game->map.width)
//		{
//			printf("count: %d\n", count++);
//			game->ray.mx = (int) (game->ray.rx) >> 6;
//			game->ray.my = (int) (game->ray.ry) >> 6;
//			game->ray.mp = game->ray.my * game->map.width;
//			if (game->ray.mp < game->map.width * game->map.height &&
//				game->map.size[game->ray.my][game->ray.mx] == '1')
//				game->ray.dof = game->map.width;
//			else
//			{
//				game->ray.rx += game->ray.xo;
//				game->ray.ry += game->ray.yo;
//				game->ray.dof += 1;
//			}
//		}
////		draw_line(game, game->player.posx, game->player.posy, 0, 0,
////				  RED);
//		game->ray.r++;
//	}
//	printf("hiii %d %d %d\n", game->ray.mp, game->ray.mx, game->ray.my);
//	printf("hi2 %d %f %f\n", game->ray.dof, game->ray.rx, game->ray.ry);
//	printf("*** %d %f %f %f %f\n", game->ray.dof, game->player.posx, game->player
//			.posy, game->ray.xo, game->ray.yo);
//	my_clear_window(game);
//	draw_minimap(game);
//	draw_miniplayer(game, 0, 0);
//	t_vec	hor;
//	t_vec	ver;
//	t_vec	min;
//
////	double hor_x = 0;
////	double hor_y = 0;
////	double ver_x = 0;
////	double ver_y = 0;
//
//	find_intersection_horizontal(game, &hor.x, &hor.y);// GREEN
//	printf("****** %f %f\n", hor.x, hor.y);
//	find_intersection_vertical(game, &ver.x, &ver.y);	// YELLOw
//	find_min_vec(hor, ver, &min);
//
//		draw_line(game, game->player.posx * 50, game->player.posy * 50,
//				min.x * 50,
//				min.y * 50, GREEN);
//		draw_scaled_point(game, min.x, min.y, GREEN);
//	/*
//	draw_line(game, game->player.posx * 50, game->player.posy * 50,
//				ver.x * 50,
//				ver.y * 50, YELLOW);
//	draw_scaled_point(game, ver.x, ver.y, YELLOW); */
//	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img, 0,
//							0);
	
	//draw_debug_map(game);
//	printf("player pos: %f %f\n", game->player.posx, game->player.posy);
//	printf("bpp %d | linelen %d\n", game->image.bits_per_pixel, game->image.line_length);
//	printf("dx==%f dy==%f da==%f\n", game->player.dx, game->player.dy, game->player.da);
//	printf(CLRSCR);
}

int	key_pressed(int key, t_game *game)
{
	key_handler(key, game);
	return (0);
}