#include "cub3D.h"

unsigned int side(t_img *image, int j, int x)
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
			rend->dist_to_wall += 0.0005;
	}
    rend->size_wall = game->image.screen_h / rend->dist_to_wall / cos(rend->dif_a);
    if (rend->size_wall > game->image.screen_h)
        rend->size_wall = game->image.screen_h;
    rend->ceil = (game->image.screen_h - rend->size_wall) / 2;
    rend->floor = (rend->ceil + rend->size_wall);
    if (!rend->dif_a)
        rend->straight = rend->dist_to_wall;
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
	rend->straight = -1;
	rend->ray_a = x * VA / SCREEN_W;
	rend->ray_a_h = (game->player.da + VA / 2) - rend->ray_a;
	rend->dif_a = game->player.da - rend->ray_a_h;
	rend->dif_a = check_rad(rend->dif_a);
	rend->y_dir = sin(rend->ray_a_h);
	rend->x_dir = cos(rend->ray_a_h);
	rend->x_dir_del = 0;
	rend->y_dir_del = 0;
}

double	fix_border(double current)
{
	double more;
	double less;
	double mid;

	more = fabs((int)current + 1 - current);
	mid = fabs((int)current - current);
	less = fabs((int)current - 1 - current);
	if (more < mid && more < less)
		current = (int)current + 1;
	else if (mid < more && mid < less)
		current = (int)current;
	else if (less < more && less < mid)
		current = (int)current - 1;
	return (current);
}

void	init_wall(t_wall *wall, t_rend *rend, int x)
{
	int num;

	num = -1;
	while (num++ < 1)
	{
		wall->side[num].max = 4;
		wall->side[num].flag = 0;
		wall->side[num].dif = 0;
		if (SCREEN_W - x - 1 <= wall->side[num].max)
			wall->side[num].max = SCREEN_W - x - 2;
	}
	wall->side[0].val = rend->x_dir_del;
	wall->side[1].val = rend->y_dir_del;
	wall->j = 0;
	wall->y = -1;
}

void	set_flag(t_wall *wall, int x, int vec)
{
	int num;

	num = -1;
	while ((num != wall[x].side[vec].max || wall[x].side[vec].max <= 0) && x + ++num +
	1 <=
	SCREEN_W)
	{
		wall[x].side[vec].dif = fabs(wall[x].side[vec].val - wall[x + num]
				.side[vec].val);
		if (fabs(wall[x + num].side[vec].val - wall[x + num + 1].side[vec].val) > 1)
		{
			wall[x].side[vec].max = num - 1;
			if (x - 1 >= 0 && !wall[x].difx)
				wall[x].side[vec].dif = fabs(wall[x].side[vec].val - wall[x - 1]
						.side[vec].val );
			break;
		}
		if (wall[x + num].side[vec].val > wall[x + num + 1].side[vec].val)
			wall[x].side[vec].flag += 1;
		else
			wall[x].side[vec].flag -= 1;
	}
}

int 	hor_ver(double x, double y)
{
	int cnt;

	cnt = 0;
	if (x / (int) x != 1)
		cnt = 1;
	if (y / (int) y != 1)
		cnt = 2;
	return (cnt);
}

void	check_borders(t_rend *rend, t_wall *wall, int x)
{
	if (x + 1 <= SCREEN_W && rend[x].x_dir_del / (int)rend[x]
			.x_dir_del != 1 && rend[x].y_dir_del / (int)rend[x]
			.y_dir_del != 1)
		set_flag(wall, x, 0);
	if (x + 1 <= SCREEN_W && rend[x].y_dir_del / (int)rend[x]
			.y_dir_del != 1 && rend[x].x_dir_del / (int)rend[x]
			.x_dir_del != 1)
		set_flag(wall, x, 1);
	if ((abs(wall[x].side[0].flag) != wall[x].side[0].max + 1) ||
		wall[x].side[0].dif < wall[x].side[1].dif)
		rend[x].x_dir_del = fix_border(wall[x].side[0].val);
	else if ((abs(wall[x].side[1].flag) != wall[x].side[1].max + 1) ||
			 wall[x].side[1].dif < wall[x].side[0].dif)
		rend[x].y_dir_del = fix_border(wall[x].side[1].val);
}

void	color_walls(t_game *game, t_rend *rend, t_wall *wall, int x)
{
	int cnt;

	check_borders(rend, wall, x);
	cnt = hor_ver(rend[x].x_dir_del, rend[x].y_dir_del);
	while (wall[x].y < rend[x].floor)
	{
		t_img *path;

		path = NULL;
		if (cnt == 1 && (x == 0 || (x - 1 >= 0 && rend[x].x_dir_del >
												  rend[x - 1].x_dir_del)))
			path = &game->path[3];
		else if (cnt == 1 && (x == 0 || (x - 1 >= 0 && rend[x].x_dir_del < rend[x - 1].x_dir_del)))
			path = &game->path[2];
		if (cnt == 2 && (x == 0 || (x - 1 >= 0 && rend[x].y_dir_del <
												  rend[x - 1].y_dir_del)))
			path = &game->path[0];
		if (cnt == 2 && (x == 0 || (x - 1 >= 0 && rend[x].y_dir_del >
												  rend[x - 1].y_dir_del)))
			path = &game->path[1];
		do_color(&game->image, (int) x, (int) wall[x].y++, \
                            side(path, (int) wall[x].j, (int) x));
		wall[x].j += (double) path->screen_h /
					 (double) rend[x].size_wall;
	}
}

void	make_3d(t_game *game, t_rend *rend, t_wall *wall)
{
	int x;

	x = -1;
    while(++x < SCREEN_W)
    {
		while (++wall[x].y < rend[x].ceil)
			do_color(&game->image, (int)x, (int)wall[x].y, f_c(game->ident
			.c_rgb));
		color_walls(game, rend, wall, x);
        while (wall[x].y < game->image.screen_h)
			do_color(&game->image, (int)x, (int)wall[x].y++, f_c(game->ident
			.f_rgb));
	}
}

void round_value(t_game *game, t_rend *rend, t_wall *wall)
{
	int x;

	x = -1;
	while(++x < SCREEN_W)
	{
		init_rend(game, &rend[x], x);
		find_ratio(game, &rend[x]);
	}
	x = -1;
	while (++x < SCREEN_W)
		init_wall(&wall[x], &rend[x], x);
}