/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:35:20 by kneth             #+#    #+#             */
/*   Updated: 2017/01/26 17:23:50 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void				itoa_neg(intmax_t *n, intmax_t *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char					*ft_itoa(intmax_t n)
{
	intmax_t		tmpn;
	intmax_t		len;
	intmax_t		neg;
	char			*str;

	if (n < -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	tmpn = n;
	len = 1;
	neg = 0;
	itoa_neg(&n, &neg);
	while (tmpn /= 10)
		len++;
	len += neg;
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
