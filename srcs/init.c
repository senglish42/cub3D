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

void 	init_screen(t_game *game)
{
	game->screen_w = 500;
	game->screen_h = 500;
}

void    init_player(t_game *game)
{
	game->player.posx = 1;
	game->player.posy = 1;
	game->player.da = 0;
	game->player.dx = cos (game->player.da) * 5;
	game->player.dy = sin (game->player.da) * 5;
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
	game->screen_w = 800;
	game->screen_h = 600;
    init_ident(&game->ident);
    init_map(game);
    init_player(game);
	init_screen(game);
}