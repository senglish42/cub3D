/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:42:00 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 15:13:39 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_walls(t_game *game, short height, short width)
{
	if (!height || (height == game->map.height - 1))
		error(7);
	if (!width || width == game->map.width - 1)
		error(7);
	if (game->map.size[height][width - 1] == ' ')
		error(7);
	if (game->map.size[height - 1][width] == ' ')
		error(7);
	if (width + 1 < game->map.width && game->map.size[height][width + 1] == ' ')
		error(7);
	if (height + 1 < game->map.height
		&& game->map.size[height + 1][width] == ' ')
		error(7);
	if (width - 1 >= 0 && height - 1 >= 0
		&& game->map.size[height - 1][width - 1] == ' ')
		error(7);
	if (width - 1 >= 0 && height + 1 < game->map.height
		&& game->map.size[height + 1][width - 1] == ' ')
		error(7);
	if (width + 1 < game->map.width && height - 1 >= 0
		&& game->map.size[height - 1][width + 1] == ' ')
		error(7);
	if (width + 1 < game->map.width && height + 1 < game->map.height
		&& game->map.size[height + 1][width + 1] == ' ')
		error(7);
}

static void	check_player(t_game *game, short height, short width)
{
	const char	player[5] = "NSWE\0";

	if (ft_memchr(player, game->map.size[height][width], ft_strlen(player) + 1))
	{
		if (!game->player.pos)
		{
			game->player.pos = &game->map.size[height][width];
			game->player.posx = (double)width + 0.5;
			game->player.posy = (double)height + 0.5;
		}
		else
			error(8);
		if (game->map.size[height][width] == 'N')
			game->player.da = PI / 2;
		else if (game->map.size[height][width] == 'S')
			game->player.da = 3 * PI / 2;
		else if (game->map.size[height][width] == 'W')
			game->player.da = PI;
		else if (game->map.size[height][width] == 'E')
			game->player.da = 2 * PI;
	}
}

void	check_map(t_game *game)
{
	short	height;
	short	width;

	height = -1;
	while (++height < game->map.height)
	{
		width = -1;
		while (++width < game->map.width)
		{
			if (game->map.size[height][width] != '1'
				&& game->map.size[height][width] != ' ')
			{
				check_player(game, height, width);
				check_walls(game, height, width);
			}
		}
	}
	if (game->player.da == -1)
		error(8);
}

static void	malloc_error(t_game *game, int num)
{
	if (num == 0)
	{
		if (!game->map.size)
			error(1);
	}
	else
	{
		if (!game->map.size[num])
		{
			while (num > -1)
				free(game->map.size[num--]);
			free(game->map.size);
			error(1);
		}
	}
}

void	fill_map(t_game *game, short num, short flag)
{
	short	count;
	short	a;

	count = -1;
	game->map.size = (char **) malloc(sizeof(char *) * game->map.height);
	malloc_error(game, 0);
	while (++count < game->map.height)
	{
		flag = 0;
		game->map.size[count] = NULL;
		game->map.size[count] = ft_calloc(game->map.width, sizeof(char *));
		malloc_error(game, count);
		a = -1;
		while (++a < game->map.width)
		{
			if (game->parse[num][a] && !flag)
				game->map.size[count][a] = game->parse[num][a];
			else
				game->map.size[count][a] = ' ';
			if (!game->parse[num][a])
				flag = 1;
		}
		game->map.size[count][a] = '\0';
		num++;
	}
}
