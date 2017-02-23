/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:46:32 by kneth             #+#    #+#             */
/*   Updated: 2016/11/15 19:08:04 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
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
