/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:24:00 by senglish          #+#    #+#             */
/*   Updated: 2022/01/26 13:02:58 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void 	init_image(t_map *map, t_img *image, t_vars *vars, t_player *player)
{
	image->screen_w = map->width * 50;
	image->screen_h = map->height * 50;
	vars->mlx = mlx_init(); // return NULL if init is failed
	vars->win = mlx_new_window(vars->mlx, image->screen_w, image->screen_h,
								   "Cub 3D");
	image->img = mlx_new_image(vars->mlx, image->screen_w,
									image->screen_h);
	printf("%f %f\n", player->posx, player->posy);
	image->addr = mlx_get_data_addr(
			image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

void    init_player(t_game *game)
{
	game->player.posx = -1;
	game->player.posy = -1;
	game->player.da = 0;
	game->player.dx = cos(game->player.da) * 5;
	game->player.dy = sin(game->player.da) * 5;
	game->player.step = 0.5f;
    game->player.pos = NULL;
    game->player.north = 0;
    game->player.south = 0;
    game->player.east = 0;
    game->player.west = 0;
}

void    init_map(t_game *game)
{
    game->map.height = 0;
    game->map.width = 0;
	game->map.scale = 0;
	game->map.size = NULL;
}

void init_ident(t_ident *ident)
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

void init_param(t_game *game)
{
    init_ident(&game->ident);
    init_map(game);
    init_player(game);
}