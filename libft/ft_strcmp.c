/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:32:42 by kneth             #+#    #+#             */
/*   Updated: 2016/11/18 16:59:14 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*fraiche;
	unsigned char	*fraiche2;

	i = 0;
	fraiche = (unsigned char*)s1;
	fraiche2 = (unsigned char*)s2;
	while (fraiche[i] && fraiche2[i] && fraiche[i] == fraiche2[i])
		i++;
	return (fraiche[i] - fraiche2[i]);
}
