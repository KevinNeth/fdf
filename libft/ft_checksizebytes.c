/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksizebytes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:35:05 by kneth             #+#    #+#             */
/*   Updated: 2017/01/27 15:36:14 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_checksizebytes(int length)
{
	int size;

	size = 0;
	if (length > 16)
		size = 4;
	else if (length > 11)
		size = 3;
	else if (length > 7)
		size = 2;
	else if (length > 0)
		size = 1;
	return (size);
}
