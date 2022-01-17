/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:31:58 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:31:59 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;

	a = 0;
	b = (unsigned char *)src;
	c = (unsigned char *)dst;
	if (!c && !b)
		return (NULL);
	while (a < len)
	{
		if (c > b)
		{
			c[len - 1] = b[len - 1];
			len--;
		}
		if (b >= c)
		{
			c[a] = b[a];
			a++;
		}
	}
	return (c);
}
