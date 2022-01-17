/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:32:49 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:32:50 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;

	a = 0;
	if (!dst && !src)
		return (0);
	while (dstsize > a)
	{
		dst[a] = src[a];
		if (!src[a])
			return (ft_strlen(src));
		a++;
	}
	dst[a - 1] = '\0';
	return (ft_strlen(src));
}
