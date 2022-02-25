/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:36:05 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 01:36:06 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	hor_ver(double x, double y)
{
	int	cnt;

	cnt = 0;
	if (x / (int) x != 1)
		cnt = 1;
	if (y / (int) y != 1)
		cnt = 2;
	return (cnt);
}

void	cmpx_cmpy(t_rend *rend, int x)
{
	double	cmpx;
	double	cmpy;

	if (rend[x].x_dir_del - (int) rend[x].x_dir_del > 0.5)
		cmpx = (int) rend[x].x_dir_del + 1 - rend[x].x_dir_del;
	else
		cmpx = (int) rend[x].x_dir_del - rend[x].x_dir_del;
	if (rend[x].y_dir_del - (int) rend[x].y_dir_del > 0.5)
		cmpy = (int) rend[x].y_dir_del + 1 - rend[x].y_dir_del;
	else
		cmpy = (int) rend[x].y_dir_del - rend[x].y_dir_del;
	if (cmpx >= cmpy && rend[x].y_dir_del - (int) rend[x].y_dir_del > 0.5)
		rend[x].y_dir_del = (int) rend[x].y_dir_del + 1;
	else if (cmpx >= cmpy && rend[x].y_dir_del - (int) rend[x].y_dir_del < 0.5)
		rend[x].y_dir_del = (int) rend[x].y_dir_del;
	if (cmpx < cmpy && rend[x].x_dir_del - (int) rend[x].x_dir_del > 0.5)
		rend[x].x_dir_del = (int) rend[x].x_dir_del + 1;
	else if (cmpx < cmpy && rend[x].x_dir_del - (int) rend[x].x_dir_del < 0.5)
		rend[x].x_dir_del = (int) rend[x].x_dir_del;
}

int	side_w(t_game *game, t_rend	*rend, int x)
{
	int	a;

	if (x == 0 || (x - 1 >= 0
			&& rend[x].x_dir_del > rend[x - 1].x_dir_del))
	{
		game->xpm[x] = game->path[3];
		a = (int)(game->xpm[x].screen_w * (rend[x].x_dir_del
					- (int)rend[x].x_dir_del));
	}
	else
	{
		game->xpm[x] = game->path[2];
		a = (int)(game->xpm[x].screen_w * ((int)rend[x].x_dir_del + 1
					- rend[x].x_dir_del));
	}
	return (a);
}

int	side_h(t_game *game, t_rend	*rend, int x)
{
	int	a;

	if (x == 0 || (x - 1 >= 0
			&& rend[x].y_dir_del < rend[x - 1].y_dir_del))
	{
		game->xpm[x] = game->path[0];
		a = (int)(game->xpm[x].screen_w * ((int)rend[x].y_dir_del + 1
					- rend[x].y_dir_del));
	}
	else
	{
		game->xpm[x] = game->path[1];
		a = (int)(game->xpm[x].screen_w * (rend[x].y_dir_del
					- (int)rend[x].y_dir_del));
	}
	return (a);
}
