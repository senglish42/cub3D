/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:59:45 by senglish          #+#    #+#             */
/*   Updated: 2022/01/22 20:26:38 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void    rgb_ident(t_ident *ident, char sep)
{
    int     count;
    char    *floor;
    char    *ceiling;

    floor = ident->orient[4];
    ceiling = ident->orient[5];
    count = -1;
    while (++count < 3)
    {
        ident->f_rgb[count] = (int)ft_atoi(floor);
        ident->c_rgb[count] = (int)ft_atoi(ceiling);
        if (ident->f_rgb[count] < 0 || ident->c_rgb[count] < 0)
            error(14);
        if (ident->f_rgb[count] > 255 || ident->c_rgb[count] > 255)
            error(14);
        floor = floor + ft_strlen(ft_itoa(ident->f_rgb[count])) + 1;
        if (sep == '0')
            sep = *(floor - 1);
        else if (*floor && sep != *(floor - 1))
            error(13);
        ceiling = ceiling + ft_strlen(ft_itoa(ident->c_rgb[count])) + 1;
        if (*ceiling && sep != *(ceiling - 1))
            error(13);
    }
}

void    compare_ident(const char *str1, const char *str2, int errno)
{
    size_t  len1;
    size_t  len2;

    len1 = ft_strlen(str1);
    len2 = ft_strlen(str2);
    if (len1 == len2)
    {
        if (!ft_strncmp(str1, str2, len1))
            error(errno);
    }
}

void    while_ident(char *orient[6])
{
    int     num;
    int     count;

    count = -1;
    while (++count < 3)
    {
        num = -1;
        while (++num <= 3)
        {
            if (num <= count)
                continue;
            compare_ident(orient[count], orient[num], 11);
        }
    }
    compare_ident(orient[4], orient[5], 12);
}

void 	fill_ident(char **turn, const char *orient, const char *str, int no)
{
	int a;

	a = no - 1;
	while (*(str + a) == ' ')
		a++;
	if (!ft_strncmp(str, orient, no))
    {
        if (!*turn)
            *turn = (char *) (str + a);
        else
            error(9);
    }
	else
		error(10);
}

void    check_ident(t_game *game, short height, short width)
{
    const char  *orient[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
    char        *str;

    str = &game->parse[height][width];
    printf("***%c\n", str[0]);
    if (*str == 'N')
        fill_ident(&game->ident.orient[0], orient[0], str, 3);
    else if (*str == 'S')
        fill_ident(&game->ident.orient[1], orient[1], str, 3);
    else if (*str == 'W')
        fill_ident(&game->ident.orient[2], orient[2], str, 3);
    else if (*str == 'E')
        fill_ident(&game->ident.orient[3], orient[3], str, 3);
    else if (*str == 'F')
        fill_ident(&game->ident.orient[4], orient[4], str, 2);
    else if (*str == 'C')
        fill_ident(&game->ident.orient[5], orient[5], str, 2);
    else
        error(10);
}

short parse_ident(t_game *game)
{
    short   height;
    short   width;

    height = -1;
    while (game->parse[++height])
        printf("%s|\n", game->parse[height]);
    height = -1;
    while (game->parse[++height] && height < 6)
    {
        width = -1;
        while (game->parse[height][++width] == ' ')
            continue;
        check_ident(game, height, width);
    }
    while_ident(game->ident.orient);
    rgb_ident(&game->ident, '0');
    return (height);
}