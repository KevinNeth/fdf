/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:36:55 by kneth             #+#    #+#             */
/*   Updated: 2016/12/15 11:40:30 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char			*ft_strndup(const char *s1, size_t n)
{
	size_t		i;
	char		*cpy;

	i = 0;
	if ((cpy = (char*)malloc(sizeof(*cpy) * (n + 1))) == NULL)
		return (NULL);
	while (i < n)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
