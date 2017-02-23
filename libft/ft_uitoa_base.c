/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:16:05 by kneth             #+#    #+#             */
/*   Updated: 2017/01/17 17:44:07 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static char		ft_check_modulo(uintmax_t modulo)
{
	if (modulo == 10)
		return ('A');
	if (modulo == 11)
		return ('B');
	if (modulo == 12)
		return ('C');
	if (modulo == 13)
		return ('D');
	if (modulo == 14)
		return ('E');
	if (modulo == 15)
		return ('F');
	return (modulo + '0');
}

char			*ft_uitoa_base(uintmax_t value, uintmax_t base)
{
	char		*str;
	uintmax_t	n;
	uintmax_t	len;
	uintmax_t	modulo;

	n = value;
	len = 2;
	if (base < 2 || base > 16)
		return (NULL);
	while (n /= base)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	len -= 1;
	str[len] = '\0';
	while (len--)
	{
		modulo = value % base;
		if (modulo > 9)
			str[len] = ft_check_modulo(modulo);
		else
			str[len] = modulo + '0';
		value /= base;
	}
	return (str);
}
