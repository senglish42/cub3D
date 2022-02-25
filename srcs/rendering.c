/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:35:57 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 01:35:58 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	f_c(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

unsigned int	side(t_img *image, int j, int x)
{
	return (*(unsigned int *)(image->addr + (j * image->line_length + x * \
	image->bits_per_pixel / 8)));
}

void	do_color(t_img *image, int x, int y, unsigned int color)
{
	my_mlx_pixel_put(image, x, y, color);
}

void	color_walls(t_game *game, t_rend *rend, t_wall *wall, int x)
{
	int		cnt;
	double	add;
	int		a;

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
		do_color(&game->image, x, (int) wall[x].y++, \
		side(&game->xpm[x], (int) wall[x].j, a));
		wall[x].j += (double)(game->xpm[x].screen_h)
			/ (double)(rend[x].size_wall);
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
		while (rend[x].floor < SCREEN_H && wall[x].y < SCREEN_H)
			do_color(&game->image, (int)x, (int)wall[x].y++,
				f_c(game->ident.f_rgb));
	}
}
