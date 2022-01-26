/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 20:14:36 by senglish          #+#    #+#             */
/*   Updated: 2022/01/26 15:42:05 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

int	if_invalid(int argc, char **argv)
{
	size_t	count;
	int		fd;

	if (argc != 2)
		error(2);
	count = ft_strlen(argv[1]);
	if (open(argv[1], O_DIRECTORY) == 1)
		error(3);
	if ((count <= 4 || ft_strncmp(&argv[1][count - 4], ".cub", 4)))
		error(3);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(4);
	return (fd);
}

int main(int argc, char **argv)
{
	t_game	game;
	int width;
	int height;

	init_param(&game);
	parse(&game, if_invalid(argc, argv));
	width = 800;
	height = 600;
	game.vars.mlx = mlx_init(); // return NULL if init is failed
	game.vars.win = mlx_new_window(game.vars.mlx, width, height,
								   "Cub 3D");
	game.image.img = mlx_new_image(game.vars.mlx, width, height);
    printf("%f %f\n", game.player.posx, game.player.posy);
	game.image.addr = mlx_get_data_addr(
			game.image.img, &game.image.bits_per_pixel, &game.image.line_length, &game.image.endian);
	mlx_put_image_to_window(game.vars.mlx, game.vars.win, game.image.img, 
							0, 0); // use win buffer ?
	game.map.scale = 8;
    mlx_key_hook(game.vars.win, key_pressed, &game);
	//mlx_hook(game.vars.win, X_EVENT_KEY_PRESS, 0, &key_pressed, &game); //
    // draw
	// path
	mlx_loop(game.vars.mlx);
	return 0;
}
