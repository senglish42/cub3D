/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:35:57 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 17:34:36 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static unsigned int	f_c(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	do_color(t_img *image, int x, int y, unsigned int color)
{
	my_mlx_pixel_put(image, x, y, color);
}

static void	color_walls(t_game *game, t_rend *rend, t_wall *wall, int x)
{
	int		cnt;
	double	add;
	int		a;
	t_point	helper;

	if (x != SCREEN_W / 2 || x != SCREEN_W / 2 - 2)
		check_borders(rend, wall, x);
	add = rend[x].ceil;
	cnt = hor_ver(rend[x].x_dir_del, rend[x].y_dir_del);
	if (cnt == 1)
		a = side_w(game, rend, x);
	else if (cnt == 2)
		a = side_h(game, rend, x);
	while (add++ < 0)
		wall[x].y--;
	if (x == 0)
		do_color(&game->image, x, (int) wall[x].y++, BLACK);
	while (x > 0 && wall[x].y < rend[x].floor && wall[x].y < SCREEN_H)
	{
		helper.x = x;
		helper.y = a;
		shadow_walls(game, rend, wall, helper);
		wall[x].y++;
	}
}

static void	color_floor(t_game *game, t_rend *rend, t_wall *wall, int x)
{
	while (rend[x].floor < SCREEN_H && wall[x].y < SCREEN_H)
	{
		if ((int)wall[x].y > rend->shadow_zone)
			do_color(&game->image, (int)x, (int)wall[x].y++,
				f_c(game->ident.f_rgb));
		else
			do_color(&game->image, (int)x, (int)wall[x].y++,
				f_c(game->ident.f_rgb) >> 1 & 8355711);
	}
}

void	make_3d(t_game *game, t_rend *rend, t_wall *wall)
{
	int	x;

	x = -1;
	while (++x < SCREEN_W)
	{
		while (++wall[x].y < rend[x].ceil && rend[x].ceil > 0)
			do_color(&game->image, (int)x, (int)wall[x].y,
				f_c(game->ident.c_rgb));
		color_walls(game, rend, wall, x);
	}
	x = -1;
	while (++x < SCREEN_W)
	{
		color_floor(game, rend, wall, x);
	}
}
