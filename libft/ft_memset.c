/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:32:03 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:32:04 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *array, int symbol, size_t bytes)
{
	size_t			a;
	unsigned char	*b;

	b = (unsigned char *)array;
	a = 0;
	while (a < bytes)
	{
		b[a] = (unsigned char)symbol;
		a++;
	}
	return (b);
}
