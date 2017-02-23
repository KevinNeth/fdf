/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:49:05 by kneth             #+#    #+#             */
/*   Updated: 2016/11/15 19:13:02 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*fraiche;

	i = 0;
	fraiche = (unsigned char*)b;
	while (i < len)
	{
		fraiche[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void		*ft_memalloc(size_t size)
{
	void	*mem;

	if ((mem = (char*)malloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
