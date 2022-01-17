/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:31:46 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:31:47 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*b;

	a = -1;
	b = (unsigned char *)s;
	while (++a < n)
	{
		if (*(b + a) == (unsigned char)c)
			return (b + a);
	}
	return (0);
}
