/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:32:41 by kneth             #+#    #+#             */
/*   Updated: 2016/11/23 13:57:38 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static int	ft_strlen_nosp(const char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i] != '\0')
	{
		n++;
		i++;
	}
	i--;
	if (n > 0)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			i--;
			n--;
		}
	}
	return (n);
}

char		*ft_strtrim(const char *s)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen_nosp(s);
	if (!(new = (char*)malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j++;
	while (i < len)
	{
		new[i] = s[j + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
