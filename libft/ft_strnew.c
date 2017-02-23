/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:40:44 by kneth             #+#    #+#             */
/*   Updated: 2016/11/15 18:32:07 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*fraiche;

	i = 0;
	if ((fraiche = (char*)malloc(sizeof(*fraiche) * size + 1)))
	{
		while (i < size)
		{
			fraiche[i] = '\0';
			i++;
		}
		fraiche[i] = '\0';
		return (fraiche);
	}
	else
		return (NULL);
}
