/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svirgil <svirgil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:59:45 by senglish          #+#    #+#             */
/*   Updated: 2022/02/26 15:09:34 by svirgil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	path_ident(char *orient[6])
{
	int		fd[4];
	char	*path;
	int		count;

	path = NULL;
	count = -1;
	while (++count < 4)
	{
		path = ft_strjoin("./images", &orient[count][1]);
		if (!path)
			printf_error(NULL, strerror(errno), fd, count);
		fd[count] = if_invalid(path, ".xpm");
		orient[count] = path;
	}
	count = -1;
	while (++count < 4)
		close(fd[count]);
}

void	to_compare(const char *str1, const char *str2, int errnum)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 == len2)
	{
		if (!ft_strncmp(str1, str2, len1))
			error(errnum);
	}
}

void	compare_ident(char *orient[6])
{
	int	num;
	int	count;

	count = -1;
	while (++count < 3)
	{
		num = -1;
		while (++num <= 3)
		{
			if (num <= count)
				continue ;
			to_compare(orient[count], orient[num], 11);
		}
	}
}

static void	fill_ident(char **turn, const char *orient, const char *str, int no)
{
	int	a;

	a = no - 1;
	while (*(str + a) == ' ')
		a++;
	if (!ft_strncmp(str, orient, no))
	{
		if (!*turn)
			*turn = (char *)(str + a);
		else
			error(9);
	}
	else
		error(10);
	if (no == 3 && ft_strncmp(*turn, "./", 2))
		error(10);
}

void	check_ident(t_game *game, short height, short width)
{
	const char	*orient[6] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	char		*str;

	str = &game->parse[height][width];
	if (*str == 'N')
		fill_ident(&game->ident.orient[0], orient[0], str, 3);
	else if (*str == 'S')
		fill_ident(&game->ident.orient[1], orient[1], str, 3);
	else if (*str == 'W')
		fill_ident(&game->ident.orient[2], orient[2], str, 3);
	else if (*str == 'E')
		fill_ident(&game->ident.orient[3], orient[3], str, 3);
	else if (*str == 'F')
		fill_ident(&game->ident.orient[4], orient[4], str, 2);
	else if (*str == 'C')
		fill_ident(&game->ident.orient[5], orient[5], str, 2);
	else
		error(10);
}
