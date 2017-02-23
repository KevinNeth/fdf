/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:35:02 by kneth             #+#    #+#             */
/*   Updated: 2016/11/18 17:10:28 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if ((dst = (char*)malloc(sizeof(*dst) * (ft_strlen(s) + 1))))
	{
		while (s[i])
		{
			dst[i] = f(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	else
		return (NULL);
}
