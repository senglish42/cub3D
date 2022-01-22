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

void 	init_location(t_map *map)
{
	map->compas.north = 0;
	map->compas.south = 0;
	map->compas.east = 0;
	map->compas.west = 0;
}

//void	player_direction(t_map *map)
//{
//	size_t	count;
//	size_t	num;
//	int 	player;
//
//	init_location(map);
//	num = 0;
//	player = 0;
//	while (map->map[++num] != map->map[map->height - 1])
//	{
//		count = 0;
//		while (map->map[num][++count] && count < map->width - 1)
//		{
//			if ((map->map[num][count] == 'N') && ++player)
//				map->compas.north = 1;
//			else if ((map->map[num][count] == 'S') && ++player)
//				map->compas.south = 1;
//			else if ((map->map[num][count] == 'E') && ++player)
//				map->compas.east = 1;
//			else if ((map->map[num][count] == 'W') && ++player)
//				map->compas.west = 1;
//		}
//	}
//	if (player != 1)
//		error(7);
//}

void	check_map(t_game *game)
{
	const char	valid[7] = " 01NSEW";
	const char 	*orient[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	int			num;
	size_t		count;
	size_t 		count1;
	int 		num1;

	num = -1;
	while (game->parse[++num])
		printf("%s|\n", game->parse[num]);
	num = -1;
	while (game->parse[++num] && game->ident.count != 6)
	{
		count = -1;
		while (game->parse[num][++count] == ' ')
			continue;
		count1 = -1;
		while (++count1 < 6 && game->ident.count == num)
		{
			if (game->parse[num][count] == 'N' && !game->ident.no)
				fill_ident(&game->ident, orient[0],&game->parse[num][count], 3);
			else if (game->parse[num][count] == 'S' && !game->ident.so)
				fill_ident(&game->ident, orient[1],&game->parse[num][count], 3);
			else if (game->parse[num][count] == 'W' && !game->ident.we)
				fill_ident(&game->ident, orient[2],&game->parse[num][count], 3);
			else if (game->parse[num][count] == 'E' && !game->ident.ea)
				fill_ident(&game->ident, orient[3],&game->parse[num][count], 3);
			else if (game->parse[num][count] == 'F' && !game->ident.f)
				fill_ident(&game->ident, orient[4],&game->parse[num][count], 2);
			else if (game->parse[num][count] == 'C' && !game->ident.c)
				fill_ident(&game->ident, orient[5],&game->parse[num][count], 2);
			else
				error(9);
		}
	}
	game->map.width = 0;
	num1 = num - 1;
	while (game->parse[++num1])
	{
		count = -1;
		while (game->parse[num1][++count])
		{
			if (!ft_strchr(valid, game->parse[num1][count]))
				error(5);
		}
		if (game->map.width < count)
			game->map.width = count;
	}
	game->map.height = num1 - num;
	printf("***\n");
	count = -1;
	while (++count < game->map.height)
	{
		game->map.size[count] = ft_calloc(game->map.width, sizeof (char *));
		size_t a;
		a = -1;
		while (++a < game->map.width)
		{
			if (game->parse[num][a])
				game->map.size[count][a] = game->parse[num][a];
			else
				game->map.size[count][a] = ' ';
		}
		game->map.size[count][a] = '\0';
		num++;
		printf("%s|\n", game->map.size[count]);
	}
	free(game->parse);
	printf("ok\n");

//	count = -1;
//	while (++count < game->map.width && game->map.map[num][count])
//	{
//		if (game->map.map[num][count] != '1' ||
//			game->map.map[num1 - 1][count] != '1')
//		{
//			if (game->map.map[num][count] != ' ' ||
//				game->map.map[num1 - 1][count] != ' ')
//				error(6);
//		}
//	}
//	count = num;
//	while (++count < game->map.height && game->map.map[count][0])
//		if (game->map.map[count][0] != '1' || game->map
//		.map[count][game->map.width - 1] != '1')
//			error(6);
//	player_direction(&game->map);
}

void	read_line(t_game *game, int fd, char *str)
{
	char	ch;
	size_t	count;
	size_t	num;

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
	char	*str;

	str = malloc(10000);
	game->map.height = 0;
	read_line(game, fd, str);
	check_map(game);
}