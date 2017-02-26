/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:51:01 by kneth             #+#    #+#             */
/*   Updated: 2017/02/26 11:14:30 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_color(t_data **pos, char **str, int *i, int *j)
{
	if (**str == '0')
		(*str)++;
	if (**str == 'x')
		(*str)++;
	pos[*i][*j].color = ft_atoi_base(*str, 16);
	*str += 6;
}

static void		ft_col(t_data **pos, char **str, int *i, int *j)
{
	while (**str == ' ' || **str == '\t' || **str == '\n')
		(*str)++;
	if (ft_isdigit(**str) || **str == '-')
		pos[*i][*j].z = ft_atoi(*str);
	pos[*i][*j].x = *j;
	pos[*i][*j].y = *i;
	while (ft_isdigit(**str) || **str == '-')
		(*str)++;
	if (**str == ',')
	{
		(*str)++;
		ft_color(pos, str, i, j);
	}
	else
		pos[*i][*j].color = 0xffffff;
	(*j)++;
}

t_data			**ft_parsing(char *str, t_mlx *info)
{
	t_data		**pos;
	int			i;
	int			j;

	i = 0;//y
	j = 0;//x
	pos = NULL;
	ft_checkvalid(str, &info->col, &info->lines);
	if (!(pos = (t_data**)malloc(sizeof(t_data*) * info->lines + 1)))
		ft_printerror(-42);
	while (i < info->lines)
	{
		if (!(pos[i] = (t_data*)malloc(sizeof(t_data) * info->col + 1)))
			ft_printerror(-42);
		while (j < info->col)
			ft_col(pos, &str, &i, &j);
		j = 0;
		i++;
	}
	/* Contenu de la struct pour debug */
	// i = 0;
	// j = 0;
	// while (i < nl)
	// {
	// 	while (j < nc)
	// 	{
	// 			printf("x = %d ", pos[i][j].x);
	// 			printf("y = %d ", pos[i][j].y);
	// 			printf("z = %d ", pos[i][j].z);
	// 			printf("color = %d\n", pos[i][j].color);
	// 		j++;
	// 	}
	// 	j = 0;
	// 	printf("%c", '\n');
	// 	i++;
	// }
	return (pos);
}
