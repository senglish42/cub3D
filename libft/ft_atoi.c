/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:31:09 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:31:10 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	int			a;
	long int	b;
	long int	c;

	a = 0;
	b = 1;
	c = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32 || str[a] == 127)
		a++;
	if (*(str + a) == '+')
		a++;
	else if (*(str + a) == '-')
	{
		b = -b;
		a++;
	}
	while (*(str + a) >= 48 && *(str + a) <= 57)
		c = c * 10 + ((*(str + a++) - 48));
	c = b * c;
	return (c);
}
