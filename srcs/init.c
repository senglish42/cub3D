/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:24:00 by senglish          #+#    #+#             */
/*   Updated: 2022/01/24 16:24:00 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    init_player(t_game *game)
{
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
    game->map.size = NULL;
}

void init_ident(t_ident *ident)
{
//    *ident->no = *ident->orient[0];
//    *ident->so = *ident->orient[1];
//    *ident->we = *ident->orient[2];
//    *ident->ea = *ident->orient[3];
//    *ident->f = *ident->orient[4];
//    *ident->c = *ident->orient[5];
    ident->orient[0] = NULL;
    ident->orient[1] = NULL;
    ident->orient[2] = NULL;
    ident->orient[3] = NULL;
    ident->orient[4] = NULL;
    ident->orient[5] = NULL;
//    printf("%p %p\n", &ident->no[0], ident->orient[0]);
//    ident->orient[0] = &ident->no[0];
//    printf("%p %p\n", &ident->no[0], ident->orient[0]);
//    ident->orient[1] = &ident->so[0];
//    ident->orient[2] = &ident->we[0];
//    ident->orient[3] = &ident->ea[0];
//    ident->orient[4] = &ident->f[0];
//    ident->orient[5] = &ident->c[0];
}

void init_param(t_game *game)
{
    init_ident(&game->ident);
    init_map(game);
    init_player(game);
}