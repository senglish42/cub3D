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
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int 	count;
}	t_ident;

typedef struct s_flag
{
	int	north;
	int	south;
	int	east;
	int	west;
}				t_flag;

typedef struct s_map
{
	char	**size;
	size_t	width;
	size_t	height;
	t_flag	compas;
	size_t	step;
	size_t	flag;
}				t_map;

typedef struct s_game
{
//	t_vars	vars;
	char 	**parse;
	t_map	map;
	t_ident	ident;
//	t_img	img;
//	t_char	character;
//	t_pos	pos;
}				t_game;

//	error.c	//
void	error(int num);

//	ident.c	//
void 	init_param(t_game *game);
void 	fill_ident(t_ident *ident, const char *orient, const char *str, int no);

//	main.c	//
int		if_invalid(int argc, char **argv);
int		main(int argc, char **argv);

//	parse.c	//
void 	init_location(t_map *map);
void	player_direction(t_map *map);
void	check_map(t_game *game);
void	read_line(t_game *game, int fd, char *str);
void	parse(t_game *game, int fd);

#endif
