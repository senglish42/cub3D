#include "cub3D.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	int ERR = 0;
	if (x <0)	ERR = 1 ;
	if (y <0)	ERR = 1 ;
	if (x >= 800)	ERR = 1 ;
	if (y >= 600)	ERR = 1 ;
	if (ERR)
	{
		printf("Error - trying to write to mem: x =%d y = %d\n", x ,y);
		return ;
	}
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_clear_window(t_game *game)
{
	int i = 0; int j = 0;
	while (i < game->screen_w)
	{
		j = 0;
		while (j < game->screen_h)
		{
			my_mlx_pixel_put(&game->image, i, j, GRAY);	j++;
		}	i++;
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
		posx = 0;
		while (posx < game->map.width)
		{
			if (posy < 8 && posx < 8)
			{
				if (game->map.size[posy][posx] == '1')
					draw_quad(game, posx * size + 1, posy * size + 1, (posx + 1)
					* size, (posy + 1) * size, WHITE);
				else
					draw_quad(game, posx * size + 1, posy * size + 1, (posx + 1)
					* size, (posy + 1) * size, BLACK);
			}
			posx++;
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

void	draw_miniplayer(t_game *game, double x, double y)
{
//	int i = 0; int j = 0;

	(void)x;
	(void)y;
	draw_scaled_point(game, game->player.posx, game->player.posy, RED);

	/*
	while (i < game->map.scale)
	{
		j = 0;
		while (j < game->map.scale)
		{
			my_mlx_pixel_put(&game->image, 50 * x + i, 50 * y + j, GREEN);
			j++;
		}
		i++;
	}
	*/
	draw_line(game, game->player.posx * 50, game->player.posy * 50,
				(game->player.posx * 50) + game->player.dx * 10,
				(game->player.posy * 50) + game->player.dy * 10, RED);
}

int check_values(int x, int y, int x1, int y1)
{
	if (x >= 0 && x < 800 && y >= 0 && y < 600 && x1 >= 0 && x1 < 800 && y1
    >= 0 && y1 < 600)
		return 1;
	return 0;
}

void    draw_line(t_game *game, double x, double y, double x1, double y1, int color)
{
	printf("\ndraw line from %f %f to %f %f", x, y, x1, y1);

	if (check_values(x, y, x1, y1) == 0)
	{
		printf("\nTry to draw impossible line\n");
		return ;
	}

	double   deltax;
    double   deltay;
    int     max;
//    int     z;
//    int     z1;

    deltax = x1 - x;
    deltay = y1 - y;

    max = MAX(ABS(deltax), ABS(deltay));
    deltay /= max; deltax /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        my_mlx_pixel_put(&game->image, x, y, color);
        x += deltax;
        y += deltay;
    }
}