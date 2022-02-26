/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:57:40 by svirgil           #+#    #+#             */
/*   Updated: 2022/02/26 12:14:09 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	player_or_space(char c)
{
	if (c == '0' || c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (TRUE);
	return (FALSE);
}

void	draw_minimap(t_game *game)
{
	t_point	pos;
	t_point	diff;
	int		size;

	pos.y = 0;
	size = 8;
	while (pos.y < game->map.height)
	{
		pos.x = -1;
		while (++pos.x < game->map.width)
		{
			diff.x = pos.x + 1;
			diff.y = pos.y + 1;
			if (player_or_space(game->map.size[pos.y][pos.x]))
				draw_quad(game, pos, diff, size);
		}
		pos.y++;
	}
}

void	draw_miniplayer(t_game *game)
{
	draw_scaled_point(game, game->player.posx, game->player.posy, YELLOW);
}

void	draw_line(t_game *game, t_vec from, t_vec to, int color)
{
	double	deltax;
	double	deltay;
	int		max;

	deltax = to.x - from.x;
	deltay = to.y - from.y;
	max = my_max(my_abs(deltax), my_abs(deltay));
	deltay /= max;
	deltax /= max;
	while ((int)(to.x - from.x) || (int)(to.y - from.y))
	{
		my_mlx_pixel_put(&game->image, from.x, from.y, color);
		from.x += deltax;
		from.y += deltay;
	}
}
