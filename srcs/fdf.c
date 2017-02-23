/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:19:37 by kneth             #+#    #+#             */
/*   Updated: 2017/02/22 16:57:09 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_event(int keycode, void *param)
{
	//printf("keycode = %d\n", keycode);//pour imprimmer le keycode
	if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx*)param)->mlx, ((t_mlx*)param)->img);
		mlx_destroy_window(((t_mlx*)param)->mlx, ((t_mlx*)param)->win);
		// free(param);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void		ft_fdf(char *str)
{
	t_mlx		info;

	ft_bzero(&info, sizeof(t_mlx));
	info.coord = ft_parsing(str, &info);
	printf("%d\n", info.lines);//mettre le max y dans lines
	printf("%d\n", info.col);//mettre le max x dans lines
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, 1000, 1000, "SDF !");
	info.img = mlx_new_image(info.mlx, IMAGEX, IMAGEY);
	ft_newmap(&info);
	mlx_hook(info.win, 2, 3, ft_event, &info);
	mlx_put_image_to_window(info.mlx, info.win, info.img, 0, 0);
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
	if (!tab)
		return (0);
	ft_fdf(tab);
	return (0);
}
