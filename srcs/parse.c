/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:59:49 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 15:15:06 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	if_invalid(const char *str, const char *format)
{
	size_t	count;
	int		fd;

	count = ft_strlen(str);
	if (open(str, O_DIRECTORY) == 1)
		error(3);
	if ((count <= 4 || ft_strncmp(&str[count - 4], format, 4)))
		error(3);
	fd = open(str, O_RDONLY);
	if (fd < 0 && format[1] == 'c')
		ft_putstr_fd("ERROR: can't read *.cub file.\n", 4);
	else if (fd < 0 && format[1] == 'x')
		ft_putstr_fd("ERROR: can't read *.xpm file.\n", 4);
	return (fd);
}

static void	parse_map(t_game *game, short num)
{
	const char	valid[7] = " 01NSWE";
	short		height;
	short		count;

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
	fill_map(game, num, 0);
	count = -1;
	while (++count < height)
		free(game->parse[count]);
	free(game->parse);
	check_map(game);
}

short	parse_ident(t_game *game)
{
	short	height;
	short	width;

	height = -1;
	while (game->parse[++height] && height < 6)
	{
		width = -1;
		while (game->parse[height][++width] == ' ')
			continue ;
		check_ident(game, height, width);
	}
	compare_ident(game->ident.orient);
	path_ident(game->ident.orient);
	rgb_ident(&game->ident);
	return (height);
}

static void	read_line(t_game *game, int fd)
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
	short	num;

	read_line(game, fd);
	num = parse_ident(game);
	parse_map(game, num);
}
