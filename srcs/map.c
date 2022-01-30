/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:42:00 by senglish          #+#    #+#             */
/*   Updated: 2022/01/25 14:15:01 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void    check_walls(t_game *game, short height, short width)
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
    if (height + 1 < game->map.height &&
        game->map.size[height + 1][width] == ' ')
        error(7);
    if (width - 1 >= 0 && height - 1 >= 0 &&
        game->map.size[height - 1][width - 1] == ' ')
        error(7);
    if (width - 1 >= 0 && height + 1 < game->map.height &&
        game->map.size[height + 1][width - 1] == ' ')
        error(7);
    if (width + 1 < game->map.width && height - 1 >= 0 &&
        game->map.size[height - 1][width + 1] == ' ')
        error(7);
    if (width + 1 < game->map.width && height + 1 < game->map.height
        && game->map.size[height + 1][width + 1] == ' ')
        error(7);
}

void check_player(t_game *game, short height, short width)
{
    const char  player[5] = "NSWE\0";

    if (ft_memchr(player, game->map.size[height][width], ft_strlen(player) + 1))
    {
        printf("***%f %f\n", game->player.posx, game->player.posy);
        if (!game->player.pos)
        {
            game->player.pos = &game->map.size[height][width];
            game->player.posx = (double)width + 0.5;
            game->player.posy = (double)height + 0.5;
            printf("***%f %f %f %f\n", game->player.posx, game->player.posy,
				   game->player.dx, game->player.dy);
        }
        else
            error(8);
        if (game->map.size[height][width] == 'S')
            game->player.da = PI / 2;
        else if (game->map.size[height][width] == 'N')
            game->player.da = 3 * PI / 2;
        else if (game->map.size[height][width] == 'W')
            game->player.da = PI;
        else if (game->map.size[height][width] == 'E')
            game->player.da = 2 * PI;
    }
}

void check_map(t_game *game)
{
    short       height;
    short       width;

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

void fill_map(t_game *game, short num)
{
	short	count;
    short	a;
	short	flag;

    count = -1;
    game->map.size = (char **) malloc(sizeof(char *) * game->map.height);
    while (++count < game->map.height)
    {
		flag = 0;
        game->map.size[count] = NULL;
        game->map.size[count] = ft_calloc(game->map.width, sizeof(char *));
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
        printf("%s|\n", game->map.size[count]);
    }
}

void parse_map(t_game *game, short num)
{
    const char  valid[7] = " 01NSWE";
    short       height;
    short       count;

    height = (short)(num - 1);
    while (game->parse[++height])
    {
        count = -1;
        while (game->parse[height][++count])
        {
            if (!ft_strchr(valid, game->parse[height][count]))
                error(6);
        }
        if (game->map.width < count)
            game->map.width = count;
    }
    game->map.height = (short)(height - num);
    fill_map(game, num);
    free(game->parse);
    check_map(game);
}