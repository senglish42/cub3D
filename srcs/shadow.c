/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:37:27 by svirgil           #+#    #+#             */
/*   Updated: 2022/02/26 14:02:21 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	do_color_dark(t_img *image, int x, int y, unsigned int color)
{
	color = color >> 1 & 8355711;
	my_mlx_pixel_put(image, x, y, color);
}

static void	do_very_dark(t_img *image, int x, int y, unsigned int color)
{
	color = color >> 1 & 8355711;
	color = color >> 1 & 8355711;
	my_mlx_pixel_put(image, x, y, color);
}

static void	do_darkness(t_img *image, int x, int y, unsigned int color)
{
	color = color >> 1 & 8355711;
	color = color >> 1 & 8355711;
	my_mlx_pixel_put(image, x, y, color);
}

static void	do_hard_dark(t_img *image, int x, int y, unsigned int color)
{
	color = color >> 1 & 8355711;
	color = color >> 1 & 8355711;
	color = color >> 1 & 8355711;
	my_mlx_pixel_put(image, x, y, color);
}

void	shadow_walls(t_game *game, t_rend *rend, t_wall *wall, t_point p)
{
	if (rend[p.x].dist_to_wall <= 3.5)
		do_color(&game->image, p.x, (int) wall[p.x].y, \
		side(&game->xpm[p.x], (int) wall[p.x].j, p.y));
	else if (rend[p.x].dist_to_wall > 5.5)
		do_hard_dark(&game->image, p.x, (int) wall[p.x].y, \
		side(&game->xpm[p.x], (int) wall[p.x].j, p.y));
	else if (rend[p.x].dist_to_wall > 5)
		do_darkness(&game->image, p.x, (int) wall[p.x].y, \
		side(&game->xpm[p.x], (int) wall[p.x].j, p.y));
	else if (rend[p.x].dist_to_wall > 4.5)
		do_very_dark(&game->image, p.x, (int) wall[p.x].y, \
		side(&game->xpm[p.x], (int) wall[p.x].j, p.y));
	else if (rend[p.x].dist_to_wall > 3.5)
		do_color_dark(&game->image, p.x, (int) wall[p.x].y, \
		side(&game->xpm[p.x], (int) wall[p.x].j, p.y));
	wall[p.x].j += (double)(game->xpm[p.x].screen_h)
		/ (double)(rend[p.x].size_wall);
}
