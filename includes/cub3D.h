/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:21:40 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 16:49:38 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "/usr/local/include/mlx.h"
# include "keys.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>

# define CLRSCR	"\e[1;1H\e[2J"

# define SCREEN_W	1200
# define SCREEN_H	800

# define PI		3.1415926
# define VA		1.0471975

# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF
# define YELLOW	0x00FFFF00
# define WHITE	0x00FFFFFF
# define BLACK	0x00000000
# define GRAY	0x00c9c0bb

# define TRUE	1
# define FALSE	0

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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		screen_w;
	int		screen_h;
}	t_img;

typedef struct s_ident
{
	char	*orient[6];
	int		f_rgb[3];
	int		c_rgb[3];
}	t_ident;

typedef struct s_player
{
	char	*pos;
	short	north;
	short	south;
	short	east;
	short	west;
	double	posx;
	double	posy;
	double	dx;
	double	dy;
	double	da;
	double	step;
	double	maxa;
	double	mina;
	double	ang[90];
	double	angx[90];
	double	angy[90];
	double	disx[90];
	double	disy[90];
}	t_player;

typedef struct s_map
{
	char	**size;
	short	width;
	short	height;
	short	scale;
}	t_map;

typedef struct s_ray
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
}	t_ray;

typedef struct s_text
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		screen_w;
	int		screen_h;
}	t_text;

typedef struct s_side
{
	int		flag;
	int		max;
	double	val;
	double	dif;
}	t_side;

typedef struct s_wall
{
	t_side	side[2];
	int		*flag;
	int		flagx;
	int		flagy;
	int		*max;
	int		maxx;
	int		maxy;
	double	j;
	double	*dif;
	double	difx;
	double	dify;
	double	y;
	int		window;
}	t_wall;

typedef struct s_rend
{
	int		hit;
	double	dist_to_wall;
	double	ray_a;
	double	ray_a_h;
	double	dif_a;
	double	y_dir;
	double	x_dir;
	double	x_dir_del;
	double	y_dir_del;
	double	size_wall;
	double	ceil;
	double	floor;
	double	straight;
	double	shadow_zone; //
}	t_rend;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	t_img		xpm[SCREEN_W];
	int			last_key;
	t_img		image;
	t_vars		vars;
	t_map		map;
	t_ident		ident;
	t_player	player;
	t_ray		ray;
	t_img		path[4];
	t_rend		rend[SCREEN_W];
	t_wall		wall[SCREEN_W];
	char		**parse;
}	t_game;

void			do_color(t_img *image, int x, int y, unsigned int color);
unsigned int	side(t_img *image, int j, int x);
void			shadow_walls(\
				t_game *game, t_rend *rend, t_wall *wall, t_point p);

//	key_handler.c	//
int				key_pressed(int key, t_game *game);
void			make_3d(t_game *game, t_rend *rend, t_wall *wall);

//	border.c	//
void			check_borders(t_rend *rend, t_wall *wall, int x);

//	draw.c	//
void			my_mlx_pixel_put(t_img *image, int x, int y, int color);
void			my_clear_window(t_game *game);
void			draw_quad(t_game *game, t_point from, t_point to, int scale);
void			draw_minimap(t_game *game);
void			draw_scaled_point(t_game *game, double x, double y, int color);
void			draw_miniplayer(t_game *game);
int				check_values(int x, int y, int x1, int y1);
void			draw_line(t_game *game, t_vec from, t_vec to, int color);

//	error.c	//
void			error(int num);
void			printf_error(char *str1, const char *str2, int *fd, int count);

//  init.c  //
void			init_param(t_game *game);
void			init_map(t_game *game);
void			init_image(t_img *image, t_vars *vars);

//	ident.c	//
void			path_ident(char *orient[6]);
void			check_ident(t_game *game, short height, short width);

//	main.c	//
void			xpm_to_image(t_game *game);
int				exit_func(t_game *game);
int				if_invalid(const char *str, const char *format);
void			to_draw(t_game *game);
int				main(int argc, char **argv);

//  map.c   //
void			check_map(t_game *game);
void			fill_map(t_game *game, short num, short flag);

//	parse.c	//
short			parse_ident(t_game *game);
void			parse(t_game *game, int fd);
void			compare_ident(char *orient[6]);

//	player.c	//
void			move_player(t_game *game, int x, int y);
void			show_map(t_game *game);

//	rendering.c	//
void			round_value(t_game *game, t_rend *rend, t_wall *wall);
void			dist_to_wall(t_game *game, int x);

//	rgb.c	//
void			rgb_ident(t_ident *ident);

//	value.c	//
void			round_value(t_game *game, t_rend *rend, t_wall *wall);

//	wall.c	//
int				side_h(t_game *game, t_rend	*rend, int x);
int				side_w(t_game *game, t_rend	*rend, int x);
void			cmpx_cmpy(t_rend *rend, int x);
int				hor_ver(double x, double y);

// minimath.c	//
int				my_abs(int x);
int				my_max(int a, int b);

#endif
