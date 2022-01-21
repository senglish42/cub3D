#include "cub3D.h"

void	error(int num)
{
	if (num == 1)
		ft_putstr_fd("ERROR: invalid number of argc.\n", 2);
	else if (num == 2)
		ft_putstr_fd("ERROR: invalid format of an argument.\n", 2);
	else if (num == 3)
		ft_putstr_fd("ERROR: can't read *.cub file.\n", 2);
	else if (num == 4)
		ft_putstr_fd("ERROR: the given map is invalid.\n", 2);
	else if (num == 5)
		ft_putstr_fd("ERROR: at least one "
					 "character of the map is invalid.\n", 2);
	else if (num == 6)
		ft_putstr_fd("ERROR: map is not fully surrounded by walls.\n", 2);
	else if (num == 7)
		ft_putstr_fd("ERROR: map should contain one player.\n", 2);
	exit (1);
}