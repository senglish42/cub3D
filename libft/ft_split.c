/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:32:29 by senglish          #+#    #+#             */
/*   Updated: 2021/11/11 13:32:30 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c);
static char		**ft_fillarray(char **res, char const *s, char c);
static int		ft_strcount(char const *s, char c);
static char		**ft_freenavalniy(char **res, int elem);

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		slova;

	if (!s)
		return (NULL);
	slova = ft_count(s, c);
	res = (char **)malloc(sizeof(char *) * slova + 1);
	if (!res)
		return (NULL);
	res = ft_fillarray(res, s, c);
	res[slova] = NULL;
	return (res);
}

static int	ft_count(char const *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (*(s + b))
	{
		if (*(s + b) != c)
		{
			a++;
			while (*(s + b) && *(s + b) != c)
				b++;
			continue ;
		}
		b++;
	}
	return (a);
}

static char	**ft_fillarray(char **res, char const *s, char c)
{
	int	d;
	int	elem;

	d = 0;
	elem = 0;
	while (*(s + d))
	{
		if (*(s + d) != c)
		{
			res[elem] = (char *)malloc(sizeof(char)
					* ft_strcount(s + d, c) + 1);
			if (!res[elem])
				return (ft_freenavalniy(res, elem));
			ft_strlcpy(res[elem++], &s[d], ft_strcount(s + d, c) + 1);
			while (*(s + d) && *(s + d) != c)
				d++;
			continue ;
		}
		d++;
	}
	return (res);
}

static int	ft_strcount(char const *s, char c)
{
	int	a;

	a = 0;
	while (*(s + a) && *(s + a) != c)
		a++;
	return (a);
}

static char	**ft_freenavalniy(char **res, int elem)
{
	while (*(res + elem) && elem > 0)
		free(res + elem--);
	free(res);
	return (NULL);
}
