/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:59:49 by senglish          #+#    #+#             */
/*   Updated: 2022/01/22 20:28:22 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

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
	compare_ident(game->ident.orient);
	path_ident(game->ident.orient);
	rgb_ident(&game->ident);
	return (height);
}

void	read_line(t_game *game, int fd)
{
	char	ch;
    char	*str;
    size_t	count;
	size_t	num;

    str = malloc(10000);
    count = 0;
	while (1)
	{
		ch = '\0';
		num = 0;
		while (ch != '\n' && ++num && read(fd, &ch, 1) > 0)
			str[count++] = ch;
		if (ch != '\n')
			str[count] = '\0';
		if (ch != '\0' && ch != '\n')
			break ;
	}
	game->parse = ft_split(str, '\n');
	free(str);
	close(fd);
}

void	parse(t_game *game, int fd)
{
    short   num;

    read_line(game, fd);
	num = parse_ident(game);
    parse_map(game, num);
}