/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:24:00 by senglish          #+#    #+#             */
/*   Updated: 2022/02/25 19:39:51 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_image(t_img *image, t_vars *vars)
{
	image->screen_w = SCREEN_W;
	image->screen_h = SCREEN_H;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (error(17));
	vars->win = mlx_new_window(vars->mlx, \
	image->screen_w, image->screen_h, "Cub 3D");
	if (vars->win == NULL)
		return (error(18));
	image->img = mlx_new_image(vars->mlx, image->screen_w, image->screen_h);
	if (image->img == NULL)
		return (error(19));
	image->addr = mlx_get_data_addr(image->img, \
	&image->bits_per_pixel, &image->line_length, &image->endian);
	if (image->addr == NULL)
		return (error(20));
}

void	init_player(t_game *game)
{
	game->last_key = -1;
	game->player.pos = NULL;
	game->player.posx = -1;
	game->player.posy = -1;
	game->player.da = -1;
	game->player.dx = 0;
	game->player.dy = 0;
	game->player.maxa = -1;
	game->player.mina = -1;
}

void	init_ray(t_game *game)
{
	game->ray.rx = 0;
	game->ray.ry = 0;
	game->ray.xo = 0;
	game->ray.yo = 0;
	game->ray.mp = 0;
	game->ray.mx = 0;
	game->ray.my = 0;
	game->ray.dof = 0;
	game->ray.r = 0;
}

void	init_ident(t_ident *ident)
{
	ident->orient[0] = NULL;
	ident->orient[1] = NULL;
	ident->orient[2] = NULL;
	ident->orient[3] = NULL;
	ident->orient[4] = NULL;
	ident->orient[5] = NULL;
	ident->f_rgb[0] = -1;
	ident->f_rgb[1] = -1;
	ident->f_rgb[2] = -1;
	ident->c_rgb[0] = -1;
	ident->c_rgb[1] = -1;
	ident->c_rgb[2] = -1;
}

void	init_param(t_game *game)
{
	init_ident(&game->ident);
	game->map.height = 0;
	game->map.width = 0;
	game->map.scale = 3;
	game->map.size = NULL;
	init_player(game);
	init_ray(game);
}
