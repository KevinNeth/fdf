/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:22:57 by kneth             #+#    #+#             */
/*   Updated: 2016/11/23 13:52:28 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	char	*ft_countstr(const char *s, char c, int g, int *n)
{
	char	*str;
	int		t;
	int		i;

	i = 0;
	while (s[*n] == c)
		++*n;
	t = *n;
	while (s[*n] != c && s[*n] != '\0')
	{
		++*n;
		g++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (g + 1))))
		return (NULL);
	str[g] = '\0';
	while (i < g)
	{
		str[i] = s[t + i];
		i++;
	}
	return (str);
}

static int		ft_countword(const char *str, char c)
{
	size_t	i;
	int		w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (i < ft_strlen(str))
			w++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (w);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		z;
	char	**tab;

	z = 0;
	i = 0;
	if (!(tab = ((char **)malloc(sizeof(char *) *
		(ft_countword(s, c) + 1)))))
		return (NULL);
	while (i < ft_countword(s, c))
	{
		tab[i] = ft_countstr(s, c, 0, &z);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
