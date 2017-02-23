/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:24:10 by kneth             #+#    #+#             */
/*   Updated: 2016/11/19 16:54:09 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (s != NULL)
	{
		if ((dst = (char*)malloc(sizeof(*dst) * len + 1)) == NULL)
			return (NULL);
		else
		{
			while (s[start + i] && i < len)
			{
				dst[i] = s[start + i];
				i++;
			}
			dst[i] = '\0';
			return (dst);
		}
	}
	return (NULL);
}
