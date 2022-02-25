/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:05:25 by senglish          #+#    #+#             */
/*   Updated: 2022/01/25 16:05:25 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	check_rgb(t_ident *ident)
{
	short	count;
	short	flag;

	count = -1;
	flag = 0;
	while (++count < 3)
	{
		if (ident->c_rgb[count] == -1 || ident->f_rgb[count] == -1)
			error(15);
		if (ident->f_rgb[count] < 0 || ident->c_rgb[count] < 0)
			error(14);
		if (ident->f_rgb[count] > 255 || ident->c_rgb[count] > 255)
			error(14);
		if (ident->f_rgb[count] == ident->c_rgb[count])
			flag++;
	}
	if (flag == 3)
		error(12);
}

char	*rgb_sep(char *str, char sep, int count)
{
	if (*str && count < 2 && sep != *str++)
		error(13);
	return (str);
}

char	*rgb_digit(char *str)
{
	while (ft_isdigit(*str))
		str++;
	return (str);
}

void	rgb_ident(t_ident *ident)
{
	int		count;
	char	sep;
	char	*floor;
	char	*ceiling;

	count = -1;
	floor = ident->orient[4];
	ceiling = ident->orient[5];
	sep = *rgb_digit(floor);
	while (*floor && *ceiling)
	{
		if (!ft_isdigit(*floor) || !ft_isdigit(*ceiling))
			error(16);
		ident->f_rgb[++count] = (int)ft_atoi(floor);
		ident->c_rgb[count] = (int)ft_atoi(ceiling);
		floor = rgb_digit(floor);
		floor = rgb_sep(floor, sep, count);
		ceiling = rgb_digit(ceiling);
		ceiling = rgb_sep(ceiling, sep, count);
	}
	check_rgb(ident);
	if (*floor || *ceiling)
		error(16);
}
