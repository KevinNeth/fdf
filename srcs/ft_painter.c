/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_painter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:32:42 by kneth             #+#    #+#             */
/*   Updated: 2017/02/26 14:59:30 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_put_color(t_mlx *info, int col1, int col2, int color)
{
	int		fcolor;
	int		differenciel;

	if (color == -1 || !info->scale || !info->zoom)
		return (0);
	if (col1 == col2)
		return (col1);
	differenciel = (col2 - col1) / (info->scale * info->zoom);
	fcolor = col1 + differenciel;
	return (fcolor);
}

void				ft_put_pixel(char *data, int sl, int x, int y, int color)
{
	int	i;

	if (x >= IMAGEX || x < 0 || y >= IMAGEY || y < 0)
		return ;
	i = sl * y + x * 4;
	data[i] = color & 0xff;
	data[++i] = color >> 8 & 0xff;
	data[++i] = color >> 16;
}

void				ft_put_line(t_mlx *info, t_xy a, t_xy b, int color)
{
	t_bresenham		badass;
	int				fcolor;

	fcolor = a.color;
	if (color == -1)
		fcolor = 0;
	badass.dx = abs(b.x - a.x);
	badass.sx = a.x < b.x ? 1 : -1;
	badass.dy = abs(b.y - a.y);
	badass.sy = a.y < b.y ? 1 : -1;
	badass.err = (badass.dx > badass.dy ? badass.dx : -badass.dy) / 2;
	badass.e2 = badass.err;
	while (1)
	{
		ft_put_pixel(info->data, info->sl, a.x, a.y, fcolor);
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
		fcolor = ft_put_color(info, fcolor, b.color, color);
	}
}
