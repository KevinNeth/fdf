/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:19:37 by kneth             #+#    #+#             */
/*   Updated: 2017/03/02 18:21:30 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_default(t_mlx *info)
{
	info->scale = SIZESCALE;
	info->sz = SIZESZ;
	info->ud = 0;
	info->rl = 0;
}

void		ft_fdf(char *str)
{
	t_mlx		info;

	ft_bzero(&info, sizeof(t_mlx));
	info.coord = ft_parsing(str, &info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WINX, WINY, "FDF !");
	info.img = mlx_new_image(info.mlx, IMAGEX, IMAGEY);
	info.data = mlx_get_data_addr(info.img, &info.bpp, &info.sl,
		 &info.endian);
	ft_default(&info);
	ft_newmap(&info);
	mlx_hook(info.win, 2, 3, ft_event, &info);
	mlx_mouse_hook(info.win, ft_mouse_event, &info);
	mlx_loop(info.mlx);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*tab;
	char	*tmp;

	if (ac < 2)
		ft_printerror(-1);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (0);
	tab = ft_strnew(0);
	while ((get_next_line(fd, &line)) > 0)
	{
		tmp = tab;
		tab = ft_strjoin(tmp, line);
		free(tmp);
		tmp = tab;
		tab = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	if (*tab == '\0' || *tab == '\n')
		ft_printerror(-1);
	ft_fdf(tab);
	return (0);
}
