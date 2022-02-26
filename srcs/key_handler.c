/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:35:46 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 16:05:51 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	up_down(t_game *game, double cos, double sin)
{
	double	x;
	double	y;
	double	step;

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

static void	left_right(t_game *game, double turn)
{
	game->player.da = game->player.da + turn;
	if (game->player.da > 2 * PI)
		game->player.da -= 2 * PI;
	else if (game->player.da < 0)
		game->player.da += 2 * PI;
	game->player.dx = cos(game->player.da);
	game->player.dy = sin(game->player.da);
	if (game->map.size[(int)game->player.posy][(int)game->player.posx] != '1')
		move_player(game, (int) game->player.posx, (int)game->player.posy);
}

static void	move_leftright(t_game *game, int key)
{
	if (key == KEY_LEFT)
	{
		if (*game->player.pos == 'N')
			up_down(game, -0.7, 0);
		if (*game->player.pos == 'S')
			up_down(game, 0.7, 0);
		if (*game->player.pos == 'W')
			up_down(game, 0, 0.7);
		if (*game->player.pos == 'E')
			up_down(game, 0, -0.7);
	}
	else
	{
		if (*game->player.pos == 'N')
			up_down(game, 0.7, 0);
		if (*game->player.pos == 'S')
			up_down(game, -0.7, 0);
		if (*game->player.pos == 'W')
			up_down(game, 0, -0.7);
		if (*game->player.pos == 'E')
			up_down(game, 0, 0.7);
	}
}

static void	move_updown(t_game *game, int key)
{
	dist_to_wall(game, SCREEN_W / 2);
	dist_to_wall(game, SCREEN_W / 2 - 2);
	if (game->rend[SCREEN_W / 2].dist_to_wall < 0.5)
	{
		if (game->rend[SCREEN_W / 2 - 2].dist_to_wall
			< game->rend[SCREEN_W / 2].dist_to_wall)
			left_right(game, -5 * PI / 180);
		else
			left_right(game, 5 * PI / 180);
	}
	else if (key == KEY_UP)
		up_down(game, game->player.dx, -game->player.dy);
	else
		up_down(game, -game->player.dx, game->player.dy);
}

int	key_pressed(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_func();
	else if (key == KEY_UP || key == KEY_DOWN)
		move_updown(game, key);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		move_leftright(game, key);
	else if (key == KEY_TURN_LEFT)
		left_right(game, 5 * PI / 180);
	else if (key == KEY_TURN_RIGHT)
		left_right(game, -5 * PI / 180);
	to_draw(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->image.img,
		0, 0);
	return (0);
}
