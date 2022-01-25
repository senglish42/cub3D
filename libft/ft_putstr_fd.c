/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:32:22 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:32:23 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	a;

	if (!s || !fd)
		return ;
	a = 0;
	while (*(s + a))
	{
		if (fd > 1)
			write(2, s + a++, 1);
		else
			write(fd, s + a++, 1);
	}
	if (fd > 1)
		exit (fd);
}