/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:36:02 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 15:20:18 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_wall(t_wall *wall, t_rend *rend, int x)
{
	int	num;

	num = -1;
	while (num++ < 1)
	{
		wall->side[num].max = 4;
		wall->side[num].flag = 0;
		wall->side[num].dif = 0;
		if (SCREEN_W - x - 1 <= wall->side[num].max)
			wall->side[num].max = SCREEN_W - x - 2;
	}
	wall->side[0].val = rend->x_dir_del;
	wall->side[1].val = rend->y_dir_del;
	wall->j = 0;
	wall->y = -1;
}

static void	find_ratio(t_game *game, t_rend *rend, int x)
{
	dist_to_wall(game, x);
	rend->size_wall = game->image.screen_h / rend->dist_to_wall
		/ cos(rend->dif_a);
	rend->ceil = (game->image.screen_h - rend->size_wall) / 2;
	rend->floor = (rend->ceil + rend->size_wall);
	if (!rend->dif_a)
		rend->straight = rend->dist_to_wall;
}

static void	init_rend(t_game *game, t_rend *rend, int x)
{
	rend->hit = 0;
	rend->dist_to_wall = 0;
	rend->straight = -1;
	rend->ray_a = x * VA / SCREEN_W;
	rend->ray_a_h = (game->player.da + VA / 2) - rend->ray_a;
	rend->dif_a = fabs(game->player.da - rend->ray_a_h);
	rend->y_dir = sin(rend->ray_a_h);
	rend->x_dir = cos(rend->ray_a_h);
	rend->x_dir_del = 0;
	rend->y_dir_del = 0;
}

void	round_value(t_game *game, t_rend *rend, t_wall *wall)
{
	int	x;

	x = -1;
	while (++x < SCREEN_W)
	{
		init_rend(game, &rend[x], x);
		find_ratio(game, &rend[x], x);
	}
	x = -1;
	while (++x < SCREEN_W)
		init_wall(&wall[x], &rend[x], x);
}
