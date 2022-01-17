/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:32:36 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:32:37 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		b;

	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!a)
		return (NULL);
	b = 0;
	while (s1[b])
	{
		a[b] = s1[b];
		b++;
	}
	a[b] = '\0';
	return (a);
}
