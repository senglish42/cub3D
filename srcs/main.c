/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:14:36 by senglish          #+#    #+#             */
/*   Updated: 2022/02/03 20:44:56 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	xpm_to_image(t_game *game)
{
	int count;

	count = -1;
	//game->path[4] = malloc(sizeof(t_img) * 4);
	while (++count < 4)
	{
		game->path[count].screen_h = game->image.screen_h / 50;
		game->path[count].screen_w = game->image.screen_w;
		printf("hii %d %d\n", game->path[count].screen_h, game->path[count]
				.screen_w);
		game->path[count].img = mlx_xpm_file_to_image(game->vars.mlx,
													  game->ident.orient[count],
													  &game->path[count].screen_w,
													  &game->path[count]
													  .screen_h);
		game->path[count].addr = mlx_get_data_addr(game->path[count].img, \
		&game->path[count].bits_per_pixel, &game->path[count].line_length,
														  &game->path[count]
														  .endian);
		free(game->ident.orient[count]);
	}
}

int	if_invalid(const char *str, const char *format)
{
	size_t	count;
	int		fd;

	count = ft_strlen(str);
	if (open(str, O_DIRECTORY) == 1)
		error(3);
	printf("1\n");
	if ((count <= 4 || ft_strncmp(&str[count - 4], format, 4)))
		error(3);
	fd = open(str, O_RDONLY);
	if (fd < 0 && format[1] == 'c')
		ft_putstr_fd("ERROR: can't read *.cub file.\n", 4);
	else if (fd < 0 && format[1] == 'x')
		ft_putstr_fd("ERROR: can't read *.xpm file.\n", 4);
	return (fd);
}

void	to_draw(t_game *game)
{
	show_map(game);
	make_3d(game);
	draw_minimap(game); //
	draw_miniplayer(game); //
//	my_clear_window(game);
//	draw_minimap(game);
//	draw_miniplayer(game);
	printf(CLRSCR);
}

int exit_func()
{
	printf("You quit the game.\n");
	exit (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(2);
	init_param(&game);
	parse(&game, if_invalid(argv[1], ".cub"));
	game.player.dx = cos(game.player.da);
	game.player.dy = sin(game.player.da);
	game.player.step = 0.5f;
	init_image(&game.image, &game.vars);
	xpm_to_image(&game);
	to_draw(&game);
	mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.image.img, 0, 0);
    mlx_key_hook(game.vars.win, key_pressed, &game); //linux
    mlx_hook(game.vars.win, 17, 1L << 17, exit_func, &game);
//	mlx_hook(game.vars.win, X_EVENT_KEY_PRESS, 0, &key_pressed, &game); //nac
	mlx_loop(game.vars.mlx);
	return 0;
}
