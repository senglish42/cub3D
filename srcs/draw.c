/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:48:57 by svirgil           #+#    #+#             */
/*   Updated: 2022/02/26 12:04:46 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;
	int		err;

	err = 0;
	if (x < 0)
		err = 1 ;
	if (y < 0)
		err = 1 ;
	if (x >= image->screen_w)
		err = 1 ;
	if (y >= image->screen_h)
		err = 1 ;
	if (err)
		return ;
	dst = (char *)image->addr + \
	(y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_clear_window(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->image.screen_w)
	{
		j = 0;
		while (j < game->image.screen_h)
		{
			my_mlx_pixel_put(&game->image, i, j, GRAY);
			j++;
		}
		i++;
	}
}

void	draw_quad(t_game *game, t_point from, t_point to, int scale)
{
	int	i;
	int	j;

	i = from.y * scale;
	while (i < to.y * scale)
	{
		j = from.x * scale;
		while (j < to.x * scale)
		{
			my_mlx_pixel_put(&game->image, j, i, BLACK);
			j++;
		}
		i++;
	}
}

void	draw_scaled_point(t_game *game, double x, double y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.scale)
	{
		j = 0;
		while (j < game->map.scale)
		{
			my_mlx_pixel_put(&game->image, 8 * x + i, 8 * y + j, color);
			j++;
		}
		i++;
	}
}
