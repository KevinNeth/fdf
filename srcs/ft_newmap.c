/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:05:06 by kneth             #+#    #+#             */
/*   Updated: 2017/02/23 21:51:39 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(char *data, int sl, int x, int y, int color)
{
	int	i;

	i = sl * y + x * 4;
	data[i] = color & 0xff;
	data[++i] = color >> 8 & 0xff;
	data[++i] = color >> 16;
}

void				ft_put_line(t_mlx *mlx, t_xy a, t_xy b, int color)
{
	t_bresenham		badass;

	badass.dx = abs(b.x - a.x);
	badass.sx = a.x < b.x ? 1 : -1;
	badass.dy = abs(b.y - a.y);
	badass.sy = a.y < b.y ? 1 : -1;
	badass.err = (badass.dx > badass.dy ? badass.dx : -badass.dy) / 2;
	badass.e2 = badass.err;
	while (1)
	{
		ft_put_pixel(mlx->data, mlx->sl, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		badass.e2 = badass.err;
		if (badass.e2 > -badass.dx)
		{
			badass.err -= badass.dy;
			a.x += badass.sx;
		}
		if (badass.e2 < badass.dy)
		{
			badass.err += badass.dx;
			a.y += badass.sy;
		}
	}
}

void		ft_newmap(t_mlx *info)
{
	int		i;
	int		j;
	t_xy	a;
	t_xy	b;
	int		scale;
	int		countmdr;

	countmdr = 1;

	i = 0;
	j = 0;
	info->data = mlx_get_data_addr(info->img, &info->bpp, &info->sl,
		&info->endian);
	while (i < info->lines)
	{
		while (j < info->col)
		{
			scale = 20;
			a.x = (((IMAGEX - ((info->col - 1) * scale)) / 2) +
				((info->coord[i][j].z + info->coord[i][j].x) * scale));
			a.y = (((IMAGEY - ((info->lines - 1) * scale)) / 2) +
				((info->coord[i][j].z + info->coord[i][j].y) * scale));

			b.x = (((IMAGEX - ((info->col - 1) * scale)) / 2) +
				((info->coord[i][j + 1].z + info->coord[i][j + 1].x) * scale));
			b.y = (((IMAGEY - ((info->lines - 1) * scale)) / 2) +
				((info->coord[i][j + 1].z + info->coord[i][j + 1].y) * scale));

			if (b.x < IMAGEX && b.x > 0 && b.y < IMAGEY && b.y > 0)
				// ft_put_pixel(info->data, info->sl, pointx, pointy, 0x00ff00);
				ft_put_line(info, a, b, 0x00ff00);
			j++;
		}
		j = 0;
		i++;
	}
}
