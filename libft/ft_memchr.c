/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:45:21 by kneth             #+#    #+#             */
/*   Updated: 2016/11/18 18:46:02 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*ch_s;

	ch_s = (const char*)s;
	i = 0;
	while (i < n)
	{
		if (ch_s[i] == (char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
