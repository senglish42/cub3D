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
	make_3d(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img,
							0, 0);
	return (0);
}