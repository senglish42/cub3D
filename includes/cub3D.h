/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:21:40 by senglish          #+#    #+#             */
/*   Updated: 2022/01/26 15:38:01 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
//# include "/usr/local/include/mlx.h"
# include "../mlx/mlx.h"
//# include "keys_macos.h"
# include "keys.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>

# define CLRSCR	"\e[1;1H\e[2J"

# define ABS(X) (((X) < 0) ? (-(X)) : (X))
# define MAX(A , B) ((A > B) ? A : B)

# define PI		3.1415926

# define TRUE	1
# define FALSE	0

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define YELLOW	0x00FFFF00
# define WHITE	0x00FFFFFF
# define BLACK	0x00000000
# define GRAY	0x00c9c0bb

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		screen_w;
	int		screen_h;
}				t_img;

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
	double	posx;
	double	posy;
	double	dx;
	double	dy;
	double	da;
	double	step;
	double 	maxa;
	double	mina;
}				t_player;

typedef struct s_map
{
	char	**size;
	short	width;
	short	height;
	short	scale;
}				t_map;

typedef struct s_ray
{
	int r;
	int mx;
	int my;
	int mp;
	int dof;
	double rx;
	double ry;
	double ra;
	double xo;
	double yo;
}	t_ray;

typedef struct s_game
{
	t_img		image;
	t_vars		vars;
	t_map       map;
	t_ident     ident;
    t_player    player;
	t_ray		ray;
	char        **parse;
}				t_game;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

////	dbg.c	//
//void	draw_debug_map(t_game *game);

//	draw.c	//
void	my_mlx_pixel_put(t_img *image, int x, int y, int color);
void	my_clear_window(t_game *game);
void	draw_quad(t_game *game, int x, int y, int x0, int y0, int color);
void	draw_minimap(t_game *game);
void 	draw_scaled_point(t_game *game, double x, double y, int color);
void	draw_miniplayer(t_game *game);
int 	check_values(int x, int y, int x1, int y1);
void    draw_line(t_game *game, double x, double y, double x1, double y1, int
color);


//	error.c	//
void    error_identifier(int num);
void	error(int num);
void	printf_error(char *str1, const char *str2, int *fd, int	count);

//  init.c  //
void 	init_param(t_game *game);
void 	init_ident(t_ident  *ident);
void 	init_map(t_game *game);
void 	init_player(t_game *game);
void 	init_image(t_map *map, t_img *image, t_vars *vars);

//	ident.c	//
void    compare_ident(const char *str1, const char *str2, int errnum);
void    while_ident(char *orient[6]);
void 	fill_ident(char **turn, const char *orient, const char *str, int no);
void    check_ident(t_game *game, short height, short width);
short 	parse_ident(t_game *game);

//	key_handler.c	//
void	key_up(t_game *game);
void	key_down(t_game *game);
void	key_left(t_game *game);
void	key_right(t_game *game);
int		key_pressed(int key, t_game *game);
void	make_3d(t_game *game);

//	main.c	//
int		if_invalid(int argc, char **argv);
void	to_draw(t_game *game);
int		main(int argc, char **argv);

//  map.c   //
void    check_walls(t_game *game, short height, short width);
void    check_player(t_game *game, short height, short width);
void    check_map(t_game *game);
void    fill_map(t_game *game, short num);
void    parse_map(t_game *game, short num);

//	parse.c	//
void	read_line(t_game *game, int fd);
void	parse(t_game *game, int fd);

//	player.c	//
void	move_player(t_game *game, int x, int y);
void	show_map(t_game *game);

//	ray.c	//
int		is_valid(int x, int y);
int		get_yray_dir(t_game *game);
int		get_xray_dir(t_game *game);
void	find_intersection_horizontal(t_game *game, double *x, double *y);
void	find_intersection_vertical(t_game *game, double *x, double *y);

//	rgb.c	//
char	*rgb_digit(char *str);
char 	*rgb_sep(char *str, char sep, int count);
void 	check_rgb(t_ident *ident);
void    rgb_ident(t_ident *ident);

//	vectors.c	//
t_vec	add_vec(t_vec a, t_vec b);
double	vec_length(t_vec vec);
t_vec	normilize_vec(t_vec vec);
t_vec	multipleByScalar(t_vec vec, double value);
double	round_down(double x);
double	round_up(double x);
void	find_min_vec(t_vec a, t_vec b, t_vec *res);

#endif
