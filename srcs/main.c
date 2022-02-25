/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:14:36 by senglish          #+#    #+#             */
/*   Updated: 2022/02/23 20:58:04 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	xpm_to_image(t_game *game)
{
	int	count;

	count = -1;
	while (++count < 4)
	{
		game->path[count].screen_h = 100;
		game->path[count].screen_w = 100;
		game->path[count].img = mlx_xpm_file_to_image(game->vars.mlx,
				game->ident.orient[count], &game->path[count].screen_w,
				&game->path[count].screen_h);
		game->path[count].addr = mlx_get_data_addr(game->path[count].img,
				&game->path[count].bits_per_pixel,
				&game->path[count].line_length,
				&game->path[count].endian);
		free(game->ident.orient[count]);
	}
}

void	to_draw(t_game *game)
{
	show_map(game);
	round_value(game, game->rend, game->wall);
	make_3d(game, game->rend, game->wall);
	draw_minimap(game);
	draw_miniplayer(game);
	printf(CLRSCR);
}

int	exit_func(void)
{
	printf("You quit the game.\n");
	exit (0);
}

void	dist_to_wall(t_game *game, int x)
{
	while (game->rend[x].hit == 0
		&& game->rend[x].dist_to_wall < game->map.width)
	{
		game->rend[x].x_dir_del = (game->player.posx + game->rend[x].x_dir
				* game->rend[x].dist_to_wall);
		game->rend[x].y_dir_del = (game->player.posy - game->rend[x].y_dir
				* game->rend[x].dist_to_wall);
		if (game->map.size[(int) game->rend[x].y_dir_del][(int)
			game->rend[x].x_dir_del] == '1')
			game->rend[x].hit = 1;
		else
			game->rend[x].dist_to_wall += 0.0005;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(2);
	init_param(&game);
	game.rend->dist_to_wall = 0.5;
	parse(&game, if_invalid(argv[1], ".cub"));
	game.player.dx = cos(game.player.da);
	game.player.dy = sin(game.player.da);
	game.player.step = 0.5f;
	init_image(&game.image, &game.vars);
	xpm_to_image(&game);
	to_draw(&game);
	mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.image.img, 0, 0);
	mlx_hook(game.vars.win, 17, 1L << 17, exit_func, &game);
	mlx_hook(game.vars.win, X_EVENT_KEY_PRESS, 0, &key_pressed, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
