/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:33:02 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:33:03 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*b;
	unsigned char	*c;

	a = 0;
	b = (unsigned char *)s1;
	c = (unsigned char *)s2;
	while (a < n)
	{
		if (b[a] != c[a])
			return (b[a] - c[a]);
		if (b[a] == '\0' || c[a] == '\0')
			break ;
		a++;
	}
	return (0);
}
