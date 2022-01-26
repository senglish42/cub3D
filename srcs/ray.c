#include "cub3D.h"

int is_valid(int x, int y)
{
	if (x >= 0 && x < 8 && y >= 0 && y < 8)
		return 1;
	return 0;
}

int get_yray_dir(t_game *game)
{
	if (game->player.dy < 0)
		return 1; // facing UP
	return 0;
}

int get_xray_dir(t_game *game)
{
	if (game->player.dx > 0)
		return 1; // facing RIGHT
	return 0;
}

void find_intersection_horizontal(t_game *game, double *x, double *y)
{
	double angle = -game->player.da;
	int ray_dir = get_yray_dir(game);

	if (ray_dir)
		*y = round_down(game->player.posy - 1);
	else
		*y = round_up(game->player.posy + 1);
	
	if (tan(angle) != 0)
		*x = game->player.posx + (game->player.posy - *y)/tan(angle);
	
	if (is_valid((int)*x, (int)*y))
		//printf("First intersection P X = %d Y = %d VALUE = %d\n", (int)*x, (int)*y, game->map.map[(int)*y][(int)*x]);
		printf("Horizontal intersiction is OK\n");
	else
	{
		printf("find_intersection_horizontal - BAD MEMORY\n");
		*x = 0; *y = 0;
		return ;
	}
	if (is_valid((int)*x, (int)*y))
		if (game->map.size[(int)*y][(int)*x] == '1' || game->map.size[(int)*y -
		1][
				(int)
		*x] == '1')
			return ;
	
	//return ;
	double Ystep; double Xstep; int delta = 0;
	if (ray_dir)
		Ystep = -1;
	else
		Ystep = 1;
	if (ray_dir)
		Xstep = 1 / tan (angle);
	else
		Xstep = -1 / tan (angle);
	if (ray_dir)
		delta = 1; // 1
	while(is_valid((int)*x, (int)*y))
	//while (game->map.map[(int)*y - delta][(int)*x] != 1) // && *x < 8 && *y < 8
	{
		if (game->map.size[(int)*y - delta][(int)*x] == '1')
			break ;
		*x = *x + Xstep;
		*y = *y + Ystep;
	}
	if (!is_valid((int)*x, (int)*y))
	{
		*x = 0; *y = 0;
	}
	//printf("Intersection P X = %d Y = %d VALUE = %d\n", 
	//	(int)*x, (int)*y - delta, game->map.map[(int)*y - delta][(int)*x]);
}

void find_intersection_vertical(t_game *game, double *x, double *y)
{
	double angle = -game->player.da;
	int ray_dir = get_xray_dir(game);
	if (ray_dir)
		*x = round_up(game->player.posx + 1);
	else
		*x = round_down(game->player.posx - 1);
	
	if (tan(angle) != 0)
		*y = game->player.posy + (game->player.posx - *x) * tan(angle);
	
	if (is_valid((int)*x, (int)*y))
		printf("Vertical: First intersection P X = %d Y = %d VALUE = %d\n",
			   (int)*x, (int)*y, game->map.size[(int)*y][(int)*x]);
	else
	{
		printf("find_intersection_horizontal - BAD MEMORY\n");
		*x = 0; *y = 0;
		return ;
	}
	if (is_valid((int)*x, (int)*y))
		if (game->map.size[(int)*y][(int)*x] == '1' || game->map.size[(int)*y][
				(int)*x - 1] == '1') // haha
			return ;
	
	//return ;

	double Ystep; double Xstep; int delta = 0;
	if (ray_dir)
		Xstep = 1;
	else
		Xstep = -1;
	if (ray_dir)
		Ystep = -1 * tan (angle);
	else
		Ystep = 1 * tan (angle);
	if (!ray_dir)
		delta = 1; // 1
	while (is_valid((int)*x, (int)*y))
	//while (game->map.map[(int)*y][(int)*x - delta] != 1) // && *x < 8 && *y < 8
	{
		if (game->map.size[(int)*y][(int)*x - delta] == '1')
			break ;
		*x = *x + Xstep;
		*y = *y + Ystep;
	}
	if (!is_valid((int)*x, (int)*y))
	{
		*x = 0; *y = 0;
	}
	//printf("Intersection P X = %d Y = %d VALUE = %d\n", 
	//	(int)*x, (int)*y - delta, game->map.map[(int)*y - delta][(int)*x]);
}