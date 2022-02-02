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
//	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img,
//							0, 0);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img,
							0, 0);
//	make_3d(game);
	return (0);
}

//void	make_3d(t_game *game)
//{
//	int x;
//	int hit;
//
//	printf("wh %d %d\n", game->image.screen_w, game->image.screen_h);
//	x = -1;
//	while(++x <= 90)
//	{
//		hit = 0;
////		if (game->player.da > 2 * PI)
////			game->player.da -= 2 * PI;
////		if (game->player.da < 0)
////			game->player.da += 2 * PI;
//		double dist_to_wall = 0;
//		double ugol_obzora = PI / 2;
//	//	double ray_a = x * ugol_obzora / game->image.screen_w;
//
//		double ray_a = x;
//		double ray_a_h = (game->player.da + ugol_obzora / 2) - ray_a;
//
//		printf("x %d ray %f %f\n", x, ray_a, ray_a_h);
////		double dif_a = game->player.da - ray_a;
//		if (ray_a_h > 2 * PI)
//			ray_a_h -= 2 * PI;
//		if (ray_a_h < 0)
//			ray_a_h += 2 * PI;
//		double y_dir = sin(ray_a_h);
//		double x_dir = cos(ray_a_h);
//		double y_dir_del;
//		double x_dir_del;
//		x_dir_del = 0;
//		y_dir_del = 0;
////		int y_h = game->player.posy;
////		int y_x =;
////		printf("%d ", game->image.screen_w);
//		while (hit == 0 && dist_to_wall < 10)
//		{
//			x_dir_del = game->player.posx + x_dir * dist_to_wall;
//			y_dir_del = game->player.posy + y_dir * dist_to_wall;
//			if (game->map.size[(int) y_dir_del][(int) x_dir_del] == '1')
//				hit = 1;
//			else
//				dist_to_wall += 0.01;
//		}
////		printf("%f ", dist_to_wall);
//		double size_wall = game->image.screen_h / dist_to_wall;
//		if (size_wall > game->image.screen_h)
//			size_wall = game->image.screen_h;
//		double ceil = (game->image.screen_h - size_wall) / 2;
//		double floor = ceil + size_wall;
//		double y = 0;
//		while (y < ceil) {
//			mlx_pixel_put(game->vars.mlx, game->vars.win, game->image.screen_w -
//														  x,
//						  (int) y,
//						  game->ident.c_rgb[0] << 16 | game->ident.c_rgb[1]
//								  << 8 | game->ident.c_rgb[2]);
//			y++;
//		}
//		//	y = ceil;
//		while (y < floor) {
//			mlx_pixel_put(game->vars.mlx, game->vars.win, game->image.screen_w -
//														  x, (int) y,
//						  255);
//			y++;
//		}
//		while (y < game->image.screen_h)
//		{
//			mlx_pixel_put(game->vars.mlx, game->vars.win, game->image.screen_w -
//														  x, (int) y,
//						  game->ident.f_rgb[0] << 16 | game->ident.f_rgb[1]
//								  << 8 | game->ident.f_rgb[2]);
//			y++;
//		}
//	}
//}

void	make_3d(t_game *game)
{
	int x;
	int hit;

	printf("wh %d %d\n", game->image.screen_w, game->image.screen_h);
	x = -1;
	while(++x <= game->image.screen_w)
	{
		hit = 0;
//		if (game->player.da > 2 * PI)
//			game->player.da -= 2 * PI;
//		if (game->player.da < 0)
//			game->player.da += 2 * PI;
		double dist_to_wall = 0;
		double ugol_obzora = PI / 2;
		double ray_a = x * ugol_obzora / game->image.screen_w;

		double ray_a_h = (game->player.da + ugol_obzora / 2) - ray_a;

		printf("x %d ray %f %f\n", x, ray_a, ray_a_h);
//		double dif_a = game->player.da - ray_a;
		if (ray_a_h > 2 * PI)
			ray_a_h -= 2 * PI;
		if (ray_a_h < 0)
			ray_a_h += 2 * PI;
		double y_dir = sin(ray_a_h);
		double x_dir = cos(ray_a_h);
		double y_dir_del;
		double x_dir_del;
		x_dir_del = 0;
		y_dir_del = 0;
//		int y_h = game->player.posy;
//		int y_x =;
//		printf("%d ", game->image.screen_w);
		while (hit == 0 && dist_to_wall < 10)
		{
			x_dir_del = game->player.posx + x_dir * dist_to_wall;
			y_dir_del = game->player.posy + y_dir * dist_to_wall;
			if (game->map.size[(int) y_dir_del][(int) x_dir_del] == '1')
				hit = 1;
			else
				dist_to_wall += 0.01;
		}
//		printf("%f ", dist_to_wall);
		double size_wall = game->image.screen_h / dist_to_wall;
		if (size_wall > game->image.screen_h)
			size_wall = game->image.screen_h;
		double ceil = (game->image.screen_h - size_wall) / 2;
		double floor = ceil + size_wall;
		double y = 0;
		while (y < ceil) {
			mlx_pixel_put(game->vars.mlx, game->vars.win, game->image.screen_w -
			x,
						  (int) y,
						  game->ident.c_rgb[0] << 16 | game->ident.c_rgb[1]
								  << 8 | game->ident.c_rgb[2]);
			y++;
		}
		//	y = ceil;
		while (y < floor) {
			mlx_pixel_put(game->vars.mlx, game->vars.win, game->image.screen_w -
														  x, (int) y,
						  255);
			y++;
		}
		while (y < game->image.screen_h)
		{
			mlx_pixel_put(game->vars.mlx, game->vars.win, game->image.screen_w -
														  x, (int) y,
						  game->ident.f_rgb[0] << 16 | game->ident.f_rgb[1]
								  << 8 | game->ident.f_rgb[2]);
			y++;
		}
	}
}

//void	make3d(t_game *game)
//{
//	int a;
//	int dof;
//	int side;
//	int mx;
//	int mp;
//	int my;
//	float disV;
//	float Tan;
//	float rx;
//	float ry;
//	float xo;
//	float yo;
//
//	a = -1;
//	while(++a < 90)
//	{
//		dof = 0;
//		side = 0;
//		disV = 100000;
//		Tan = tan(game->player.da);
//		if (cos(game->player.da) > 0.001)
//		{
//			rx = (((int)game->player.posx >> 6) << 6) + 64;
//			ry = (game->player.posx - rx) * Tan + game->player.posy;
//			xo = 64;
//			yo = -xo * Tan;
//		}
//		else if (cos(game->player.da) < -0.001)
//		{
//			rx = (((int)game->player.posx >> 6) << 6) - 0.0001;
//			ry = (game->player.posx - rx) * Tan + game->player.posy;
//			xo = -64;
//			yo = -xo * Tan;
//		}
//		else
//		{
//			rx = game->player.posx;
//			ry = game->player.posy;
//			dof = 8;
//		}
//		while (dof < 8)
//		{
//			mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*game->map.width+mx;
//			if(mp>0 && mp<game->map.width*game->map.height &&
//			game->map.size[mp]=='1'){
//				dof=8; disV=cos(game->player.da)*(rx-game->player.posx)-sin
//						(game->player.da)*(ry-game->player.posy);}//hit
//			else{ rx+=xo; ry+=yo; dof+=1;}
//		}
//	}
//}