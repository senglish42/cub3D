/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:33:08 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:33:09 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrchr(const void *s, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s + n - 1;
	while (n > 0)
	{
		if (*b == (unsigned char)c)
			return (b);
		b--;
		n--;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	return (ft_memrchr(s, c, ft_strlen(s) + 1));
}
