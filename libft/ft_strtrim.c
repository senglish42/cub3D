/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:33:13 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:33:14 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		slen;
	char		*res;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	slen = ft_strlen(s1);
	while (slen && ft_strrchr(set, s1[slen]))
		slen -= 1;
	res = ft_substr((char *)s1, 0, slen + 1);
	return (res);
}
