#include "cub3D.h"

void 	init_location(t_map *map)
{
	map->compas.north = 0;
	map->compas.south = 0;
	map->compas.east = 0;
	map->compas.west = 0;
}

void	player_direction(t_map *map)
{
	size_t	count;
	size_t	num;
	int 	player;

	init_location(map);
	num = 0;
	player = 0;
	while (map->map[++num] != map->map[map->height - 1])
	{
		count = 0;
		while (map->map[num][++count] && count < map->width - 1)
		{
			if ((map->map[num][count] == 'N') && ++player)
				map->compas.north = 1;
			else if ((map->map[num][count] == 'S') && ++player)
				map->compas.south = 1;
			else if ((map->map[num][count] == 'E') && ++player)
				map->compas.east = 1;
			else if ((map->map[num][count] == 'W') && ++player)
				map->compas.west = 1;
		}
	}
	if (player != 1)
		error(7);
}

void	check_map(t_map *map)
{
	const char	valid[6] = "01NSEW";
	int			num;
	size_t		count;

	num = -1;
	while (map->map[++num])
	{
		count = -1;
		while (map->map[num][++count])
			if (!ft_strchr(valid, map->map[num][count]))
				error(5);
	}
	count = -1;
	while (++count < map->width && map->map[0][count])
		if (map->map[0][count] != '1' ||
			map->map[map->height - 1][count] != '1')
			error(6);
	count = -1;
	while (++count < map->height && map->map[count][0])
		if (map->map[count][0] != '1' || map->map[count][map->width - 1] != '1')
			error(6);
	player_direction(map);
}

void	width_height(t_map *map, int fd, char *str)
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
		if (ch != '\0' && ++map->height && map->height == 1)
			map->width = num - 1;
		if (map->width && (num - 1 != map->width || num == 0))
			error(4);
		if (ch != '\0' && ch != '\n')
			break ;
	}
	map->map = ft_split(str, '\n');
	free(str);
	close(fd);
}

void	parse(t_map *map, int fd)
{
	char	*str;

	str = malloc(10000);
	map->height = 0;
	width_height(map, fd, str);
	check_map(map);
}