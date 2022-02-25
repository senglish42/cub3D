/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:35:54 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 01:35:55 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(t_game *game, int x, int y)
{
	if (game->map.size[y][x] != *game->player.pos)
	{
		*game->player.pos = '0';
		game->player.pos = &game->map.size[y][x];
	}
	if (game->player.da >= PI / 4 && game->player.da < 3 * PI / 4)
		game->map.size[(int) game->player.posy][(int) game->player.posx] = 'N';
	else if (game->player.da >= 5 * PI / 4 && game->player.da < 7 * PI / 4)
		game->map.size[(int) game->player.posy][(int) game->player.posx] = 'S';
	else if (game->player.da >= 3 * PI / 4 && game->player.da < 5 * PI / 4)
		game->map.size[(int) game->player.posy][(int) game->player.posx] = 'W';
	else if (game->player.da >= 7 * PI / 4 || game->player.da < PI / 4)
		game->map.size[(int)y][(int)x] = 'E';
	game->player.pos = &game->map.size[(int)game->player.posy] \
		[(int)game->player.posx];
}

void	show_map(t_game *game)
{
	int	a;

	a = -1;
	while (++a < game->map.height)
		printf("%s\n", game->map.size[a]);
}
