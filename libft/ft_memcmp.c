/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:31:50 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:31:51 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;

	a = -1;
	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (++a < n)
	{
		if (*(b + a) != *(c + a))
			return (*(b + a) - *(c + a));
	}
	return (0);
}
