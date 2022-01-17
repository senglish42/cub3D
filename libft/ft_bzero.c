/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:31:14 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:31:15 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *array, size_t bytes)
{
	size_t	a;
	char	*b;

	a = 0;
	b = (char *)array;
	while (a < bytes)
	{
		b[a] = 0;
		a++;
	}
}
