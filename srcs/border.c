/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:35:16 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 01:35:17 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	fix_border(double current)
{
	double	more;
	double	less;
	double	mid;

	more = fabs((int)current + 1 - current);
	mid = fabs((int)current - current);
	less = fabs((int)current - 1 - current);
	if (more < mid && more < less)
		current = (int)current + 1;
	else if (mid < more && mid < less)
		current = (int)current;
	else if (less < more && less < mid)
		current = (int)current - 1;
	return (current);
}

void	set_flag(t_wall *wall, int x, int vec)
{
	int	num;

	num = -1;
	while ((num != wall[x].side[vec].max || wall[x].side[vec].max <= 0)
		&& x + ++num + 1 <= SCREEN_W)
	{
		wall[x].side[vec].dif = fabs(wall[x].side[vec].val - wall[x + num]
				.side[vec].val);
		if (fabs(wall[x + num].side[vec].val
				- wall[x + num + 1].side[vec].val) > 1)
		{
			wall[x].side[vec].max = num - 1;
			if (x - 1 >= 0 && !wall[x].difx)
				wall[x].side[vec].dif = fabs(wall[x].side[vec].val
						- wall[x - 1].side[vec].val);
			break ;
		}
		if (wall[x + num].side[vec].val > wall[x + num + 1].side[vec].val)
			wall[x].side[vec].flag += 1;
		else
			wall[x].side[vec].flag -= 1;
	}
}

void	check_borders(t_rend *rend, t_wall *wall, int x)
{
	if (x + 1 <= SCREEN_W && rend[x].x_dir_del / (int)rend[x].x_dir_del != 1
		&& rend[x].y_dir_del / (int)rend[x].y_dir_del != 1)
		set_flag(wall, x, 0);
	if (x + 1 <= SCREEN_W && rend[x].y_dir_del / (int)rend[x].y_dir_del != 1
		&& rend[x].x_dir_del / (int)rend[x].x_dir_del != 1)
		set_flag(wall, x, 1);
	if ((abs(wall[x].side[0].flag) != wall[x].side[0].max + 1)
		|| wall[x].side[0].dif < wall[x].side[1].dif)
		rend[x].x_dir_del = fix_border(wall[x].side[0].val);
	else if ((abs(wall[x].side[1].flag) != wall[x].side[1].max + 1)
		|| wall[x].side[1].dif < wall[x].side[0].dif)
		rend[x].y_dir_del = fix_border(wall[x].side[1].val);
	if (x > 0 && rend[x].x_dir_del / (int)rend[x].x_dir_del != 1
		&& rend[x].y_dir_del / (int)rend[x].y_dir_del != 1)
		cmpx_cmpy(rend, x);
}
