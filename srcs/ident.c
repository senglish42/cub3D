/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:59:45 by senglish          #+#    #+#             */
/*   Updated: 2022/01/22 20:26:38 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void init_param(t_game *game)
{
	game->ident.no = NULL;
	game->ident.so = NULL;
	game->ident.we = NULL;
	game->ident.ea = NULL;
	game->ident.f = NULL;
	game->ident.c = NULL;
	game->ident.count = 0;
}

void 	fill_ident(t_ident *ident, const char *orient, const char *str, int no)
{
	int a;

	a = -1;
	while (*(str + ++a) == ' ')
		continue;
	if (!ft_strncmp(str, orient, no) && ++ident->count)
		ident->no = (char *)(str + a);
	else
		error(8);
}
