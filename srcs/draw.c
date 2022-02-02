#include "cub3D.h"

void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	int ERR = 0;
	if (x < 0)	ERR = 1 ;
	if (y < 0)	ERR = 1 ;
	if (x >= image->screen_w)	ERR = 1 ;
	if (y >= image->screen_h)	ERR = 1 ;
	if (ERR)
	{
		printf("Error - trying to write to mem: x =%d y = %d %d %d\n", x ,y,
			   image->screen_w, image->screen_h);
		return ;
	}
	dst = image->addr + (y * image->line_length + x *
			(image->bits_per_pixel /
			8));
	*(unsigned int*)dst = color;
}

void	my_clear_window(t_game *game)
{
	int i = 0;
	int j;

	while (i < game->image.screen_w)
	{
		j = 0;
		while (j < game->image.screen_h)
		{
			my_mlx_pixel_put(&game->image, i, j, GRAY);
			j++;
		}
		i++;
	}
}

void	draw_quad(t_game *game, int x, int y, int x0, int y0, int color)
{
	int i = y;
	int j = x;

	while (i < y0)
	{
		j = x;
		while (j < x0)
		{
			my_mlx_pixel_put(&game->image, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int posx = 0;
	int posy = 0;
	int size = 50;

	while (posy < game->map.height)
	{
		posx = -1;
		while (++posx < game->map.width)
		{
//			if (posy < 8 && posx < 8)
//			{
				if (game->map.size[posy][posx] == '1')
					draw_quad(game, posx * size + 1, posy * size + 1, (posx + 1)
					* size, (posy + 1) * size, WHITE);
				else
					draw_quad(game, posx * size + 1, posy * size + 1, (posx + 1)
					* size, (posy + 1) * size, BLACK);
//			}
//			posx++;
		}
		posy++;
	}
}

void draw_scaled_point(t_game *game, double x, double y, int color)
{
	int i = 0;
	int j = 0;

	while (i < game->map.scale)
	{
		j = 0;
		while (j < game->map.scale)
		{
			my_mlx_pixel_put(&game->image, 50 * x + i, 50 * y + j, color);
			j++;
		}
		i++;
	}
}

//static void distance()
//{
//	cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay)
//}

void	draw_miniplayer(t_game *game)
{
	double	x1;
	double	y1;
	double	num;
	double	dx;
	double	dy;
	int		count;
	double	min;
	double 	max;
	int 	cnt;

	cnt = 0;
	count = -1;
	min = game->player.da - PI / 4;
	max = game->player.da + PI / 4;
	num = - 45 * PI / 180;
	while (++count != 450)
	{
		if ((num >= min && num <= max))
		{
			dx = cos(num);
			dy = sin(num);
			game->player.disx[cnt] = 100000000;
			x1 = game->player.posx * 50;
			y1 = game->player.posy * 50;
			while (game->map.size[(int)
			(y1 / 50)][(int)(x1/ 50)]!= '1')
			{
				x1 = x1 + dx;
				y1 = y1 - dy;
			}
			if ((int)(x1 + 1) % 50 == 0)
				x1 = (int)(x1 + 1);
			else if ((int)(x1 - 1) % 50 == 0)
				x1 = (int)(x1 - 1);
			else
				x1 = (int)x1;
			if ((int)(y1 + 1) % 50 == 0)
				y1 = (int)(y1 + 1);
			else if ((int)(y1 - 1) % 50 == 0)
				y1 = (int)(y1 - 1);
			else
				y1 = (int)y1;
			if ((int)(num * 100) == (int)(game->player.da * 100))
				draw_line(game, game->player.posx * 50, game->player.posy * 50,
						  x1,y1,GREEN);
			else
				draw_line(game, game->player.posx * 50, game->player.posy *
														50, x1,y1,RED);
			if (count == 0)
				game->player.mina = num;
			else
				game->player.maxa = num;
			game->player.ang[cnt] = num;
			game->player.angx[cnt] = x1 / 50;
			game->player.angy[cnt] = y1 / 50;
			double x2;
			double y2;
//
			if (game->player.posx >= game->player.angx[cnt])
				x2 = game->player.angx[cnt] - game->player.posx;
			else
				x2 = game->player.posx - game->player.angx[cnt];
			if (game->player.posy >= game->player.angy[cnt])
				y2 = game->player.angy[cnt] - game->player.posy;
			else
				y2 = game->player.posy - game->player.angy[cnt];
			game->player.disx[cnt] = sqrt((game->player.posx - game->player
					.angx[cnt]) * (game->player.posx - game->player
					.angx[cnt]) + (game->player.posy - game->player
							.angy[cnt]) * (game->player.posy - game->player
									.angy[cnt]));
		//	printf("dist %f\n", game->player.disx[cnt]);
			cnt++;
		}
		num += PI / 180;
	}
//	cnt = -1;
//	while (++cnt < 90)
//		printf("dist %f %f %f %f %f\n", cos(num) * (game->player
//		.posx -
//		game->player.angx[cnt]), sin(num) * (game->player
//				.posy - game->player
//		.angy[cnt]), game->player.angx[cnt], game->player.angy[cnt],
//			   game->player.disx[cnt]);
	draw_scaled_point(game, game->player.posx, game->player.posy, YELLOW);
}

void    draw_line(t_game *game, double x, double y, double x1, double y1, int color)
{
	//printf("\ndraw line from %f %f to %f %f", x, y, x1, y1);

	double   deltax;
	double   deltay;
	int     max;

	deltax = x1 - x;
	deltay = y1 - y;

	max = MAX(ABS(deltax), ABS(deltay));
	deltay /= max; deltax /= max;
	while ((int)(x1 - x) || (int)(y1 - y))
	{
		my_mlx_pixel_put(&game->image, x, y, color);
		x += deltax;
		y += deltay;
	}
}