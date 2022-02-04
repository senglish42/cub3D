#include "cub3D.h"

void	up_down(t_game *game, double cos, double sin)
{
	double	x;
	double	y;
	double 	step;

	step = 0.3;
	x = game->player.posx;
	y = game->player.posy;
	while (game->map.size[(int)y][(int)x] != '1' && step > 0)
	{
		x = game->player.posx + cos * step;
		y = game->player.posy + sin * step;
		if (game->map.size[(int)y][(int)x] == '1')
		{
			step -= 0.1;
			x = game->player.posx - cos * step;
			y = game->player.posy - sin * step;
		}
		else
			break ;
	}
	move_player(game, (int)x, (int)y);
	game->player.posx = x;
	game->player.posy = y;
}

void	left_right(t_game *game, double turn)
{
	game->player.da = game->player.da + turn;
	game->player.da = check_rad(game->player.da);
	game->player.dx = cos(game->player.da);
	game->player.dy = sin(game->player.da);
	if (game->map.size[(int)game->player.posy][(int)game->player.posx] != '1')
		move_player(game, (int) game->player.posx, (int)game->player.posy);
}

int	key_pressed(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_func();
	else if (key == KEY_UP)
		up_down(game, game->player.dx, -game->player.dy);
	else if (key == KEY_DOWN)
		up_down(game, -game->player.dx, game->player.dy);
	else if (key == KEY_LEFT)
		left_right(game, 5 * PI / 180);
	else if (key == KEY_RIGHT)
		left_right(game, -5 * PI / 180);
	to_draw(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img,
							0, 0);
	return (0);
}