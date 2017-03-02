/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eventmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:47:05 by kneth             #+#    #+#             */
/*   Updated: 2017/03/02 18:28:44 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_event(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx*)param)->mlx, ((t_mlx*)param)->img);
		mlx_destroy_window(((t_mlx*)param)->mlx, ((t_mlx*)param)->win);
		// free(param);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->sz += 1;
		ft_newmap(param);
	}
	if (keycode == 1)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->sz -= 1;
		ft_newmap(param);
	}
	if (keycode == 49)
	{
		ft_cleanmap(param);
		ft_default(param);
		ft_newmap(param);
	}
	if (keycode == 126)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->ud -= 3;
		ft_newmap(param);
	}
	if (keycode == 125)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->ud += 3;
		ft_newmap(param);
	}
	if (keycode == 124)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->rl += 3;
		ft_newmap(param);
	}
	if (keycode == 123)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->rl -= 3;
		ft_newmap(param);
	}
	return (0);
}

int		ft_mouse_event(int button, int x, int y, void *param)
{
	int 	i;
	int		j;

	i = x;
	j = y;
	if (button == 4)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->scale += 1;
		ft_newmap(param);
	}
	if (button == 5)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->scale -= 1;
		ft_newmap(param);
	}
	return (0);
}
