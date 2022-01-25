/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:21:40 by senglish          #+#    #+#             */
/*   Updated: 2022/01/22 20:06:46 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_ident
{
    char    *orient[6];
	int     f_rgb[3];
    int     c_rgb[3];
}	t_ident;

typedef struct s_player
{
    char    *pos;
	short   north;
	short   south;
	short   east;
	short   west;
}				t_player;

typedef struct s_map
{
	char	**size;
	short	width;
	short	height;
	size_t	step;
	size_t	flag;
}				t_map;

typedef struct s_game
{
//	t_vars	vars;
	char        **parse;
	t_map       map;
	t_ident     ident;
    t_player    player;
//	t_img	img;
//	t_char	character;
//	t_pos	pos;
}				t_game;

//	error.c	//
void	error(int num);

//  init.c  //
void 	init_param(t_game *game);
void 	init_ident(t_ident  *ident);
void 	init_map(t_game *game);
void 	init_player(t_game *game);

//	ident.c	//
void    rgb_ident(t_ident *ident, char sep);
void    compare_ident(const char *str1, const char *str2, int errno);
void    while_ident(char *orient[6]);
void 	fill_ident(char **turn, const char *orient, const char *str, int no);
void    check_ident(t_game *game, short height, short width);
short 	parse_ident(t_game *game);

//	main.c	//
int		if_invalid(int argc, char **argv);
int		main(int argc, char **argv);

//  map.c   //
void    check_walls(t_game *game, short height, short width);
void    check_player(t_game *game, short height, short width);
void    check_map(t_game *game);
void    fill_map(t_game *game, short num);
void    parse_map(t_game *game, short num);

//	parse.c	//
void 	init_location(t_map *map);
void	player_direction(t_map *map);
void	read_line(t_game *game, int fd);
void	parse(t_game *game, int fd);

#endif
