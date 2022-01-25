/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:59:59 by senglish          #+#    #+#             */
/*   Updated: 2022/01/22 11:00:07 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void    error_identifier(int num)
{
    if (num == 9)
        ft_putstr_fd("ERROR: structure identification is already set\n", num);
    else if (num == 10)
        ft_putstr_fd("ERROR: .xpm identification is invalid\n", num);
    else if (num == 11)
        ft_putstr_fd("ERROR: .xpm identification id duplicated\n", num);
    else if (num == 12)
        ft_putstr_fd("ERROR: floor and ceiling should be different color\n",
                     num);
    else if (num == 13)
        ft_putstr_fd("ERROR: invalid sign of an identifier's separator\n",num);
    else if (num == 14)
        ft_putstr_fd("ERROR: invalid value of the RGB identifier\n", num);
}

void	error(int num)
{
	if (num == 2)
		ft_putstr_fd("ERROR: invalid number of argc.\n", num);
	else if (num == 3)
		ft_putstr_fd("ERROR: invalid format of an argument.\n", num);
	else if (num == 4)
		ft_putstr_fd("ERROR: can't read *.cub file.\n", num);
	else if (num == 5)
		ft_putstr_fd("ERROR: the given map is invalid.\n", num);
	else if (num == 6)
		ft_putstr_fd("ERROR: at least one "
					 "character of the map is invalid.\n", num);
	else if (num == 7)
		ft_putstr_fd("ERROR: map is not fully surrounded by walls.\n", num);
	else if (num == 8)
		ft_putstr_fd("ERROR: map should contain one player.\n", num);
    else if (num >= 9)
        error_identifier(num);
}