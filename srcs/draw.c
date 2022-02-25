/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:48:57 by svirgil           #+#    #+#             */
/*   Updated: 2022/02/25 20:35:31 by svirgil          ###   ########.fr       */
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

void	draw_quad(t_game *game, int x, int y, int x0, int y0, int color)
{
	int	i;
	int	j;

	i = y;
	j = x;
	while (i < y0)
	{
		j = x;
		while (j < x0)
		{
			my_mlx_pixel_put(&game->image, j, i, color);
			j++;
		}
		i++;
	}
}

static int	player_or_space(char c)
{
	if (c == '0' || c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (TRUE);
	return (FALSE);
}

void	draw_minimap(t_game *game)
{
	int	posx;
	int	posy;
	int	size;

	posx = 0;
	posy = 0;
	size = 8;
	while (posy < game->map.height)
	{
		posx = -1;
		while (++posx < game->map.width)
		{
			if (player_or_space(game->map.size[posy][posx]))
				draw_quad(game, posx * size, posy * size, \
				(posx + 1) * size, (posy + 1) * size, BLACK);
		}
		posy++;
	}
}

void	draw_scaled_point(t_game *game, double x, double y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

void	draw_miniplayer(t_game *game)
{
	draw_scaled_point(game, game->player.posx, game->player.posy, YELLOW);
}

void	draw_line(t_game *game, double x, double y, double x1, double y1, int color)
{
	double	deltax;
	double	deltay;
	int		max;

	deltax = x1 - x;
	deltay = y1 - y;
	max = MAX(ABS(deltax), ABS(deltay));
	deltay /= max;
	deltax /= max;
	while ((int)(x1 - x) || (int)(y1 - y))
	{
		my_mlx_pixel_put(&game->image, x, y, color);
		x += deltax;
		y += deltay;
	}
}
