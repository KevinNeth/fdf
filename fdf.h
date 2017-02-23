/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:45:36 by kneth             #+#    #+#             */
/*   Updated: 2017/02/23 21:49:43 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "./libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
#include <stdlib.h>// a virer

# define SCALE 10
# define TRANSLATION 100
# define IMAGEX 1000
# define IMAGEY 1000

typedef	struct		s_data
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_data;

typedef struct		s_mlx
{
	t_data			**coord;
	int				lines;
	int				col;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				sl;
	int				bpp;
	int				endian;
}					t_mlx;

typedef struct		s_bresenham
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bresenham;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

void				ft_checkvalid(char *str, int *nl, int *nc);
t_data				**ft_parsing(char *str, t_mlx *info);
void				ft_printerror(int i);
void				ft_put_line(t_mlx *info, t_xy a, t_xy b, int color);
void				ft_put_pixel(char *data, int sl, int x, int y, int color);
void				ft_newmap(t_mlx *info);

void				ft_errors();

#endif
