/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:05:06 by kneth             #+#    #+#             */
/*   Updated: 2017/02/25 19:26:13 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void			ft_color()
// {
//
// }

void			ft_printer_hor(t_mlx *info, int i, int j, int color)
{
	t_xy	a;
	t_xy	b;

	a.x = ((IMAGEX - ((info->col - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i][j].z * SZ / 8) + info->coord[i][j].x * SCALE) * ZOOM) + RL;
	a.y = ((IMAGEY - ((info->lines - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i][j].z * SZ / 8) + info->coord[i][j].y * SCALE) * ZOOM) + UD;
	b.x = ((IMAGEX - ((info->col - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i][j + 1].z * SZ / 8) + info->coord[i][j + 1].x * SCALE) * ZOOM) + RL;
	b.y = ((IMAGEY - ((info->lines - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i][j + 1].z * SZ / 8) + info->coord[i][j + 1].y * SCALE) * ZOOM) + UD;
	ft_put_line(info, a, b, color);
}

void			ft_printer_ver(t_mlx *info, int i, int j, int color)
{
	t_xy	a;
	t_xy	b;

	a.x = ((IMAGEX - ((info->col - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i][j].z * SZ / 8) + info->coord[i][j].x * SCALE) * ZOOM) + RL;
	a.y = ((IMAGEY - ((info->lines - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i][j].z * SZ / 8) + info->coord[i][j].y * SCALE) * ZOOM) + UD;
	b.x = ((IMAGEX - ((info->col - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i + 1][j].z * SZ / 8) + info->coord[i + 1][j].x * SCALE) * ZOOM) + RL;
	b.y = ((IMAGEY - ((info->lines - 1) * SCALE * ZOOM)) / 2) +
		(((info->coord[i + 1][j].z * SZ / 8) + info->coord[i + 1][j].y * SCALE) * ZOOM) + UD;
	ft_put_line(info, a, b, color);
}

void			ft_cleanmap(t_mlx *info)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	color = 0x000000;
	printf("lines = %d\n", info->lines);
	printf("col = %d\n", info->col);
	while (i < info->lines)
	{
		while (j < info->col)
		{

			if (j + 1 < info->col)
				ft_printer_hor(info, i, j, color);
			if (i + 1 < info->lines)
				ft_printer_ver(info, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	printf("%s\n", "wtffff");
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

void			ft_newmap(t_mlx *info)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	j = 0;
	color = 0x00ff00;
	while (i < info->lines)
	{
		while (j < info->col)
		{
			if (j + 1 < info->col)
				ft_printer_hor(info, i, j, color);
			if (i + 1 < info->lines)
				ft_printer_ver(info, i, j, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}
