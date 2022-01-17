/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:32:46 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:32:47 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	c;

	if (!dst && !src)
		return (0);
	a = 0;
	b = ft_strlen(dst);
	c = ft_strlen(dst) + ft_strlen(src);
	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	while (b < dstsize - 1 && a < ft_strlen(src))
		dst[b++] = src[a++];
	dst[b] = '\0';
	return (c);
}
