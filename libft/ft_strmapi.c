/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:32:57 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:32:58 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	b;

	if (!s || !f)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (a == NULL)
		return (NULL);
	b = 0;
	while (s[b])
	{
		a[b] = f(b, s[b]);
		b++;
	}
	a[b] = '\0';
	return (a);
}
