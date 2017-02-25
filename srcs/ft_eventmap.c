/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eventmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:47:05 by kneth             #+#    #+#             */
/*   Updated: 2017/02/25 19:14:55 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_event(int keycode, void *param)
{
	printf("keycode = %d\n", keycode);//pour imprimmer le keycode
	if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx*)param)->mlx, ((t_mlx*)param)->img);
		mlx_destroy_window(((t_mlx*)param)->mlx, ((t_mlx*)param)->win);
		// free(param);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 2)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->sz += 1;
		ft_newmap(param);
	}
	if (keycode == 0)
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
	return (0);
}

int		ft_mouse_event(int button, int x, int y, void *param)
{
	//4 scroll avant
	//5 scroll arriere
	printf("button : %d\n", button);
	printf("mouse [x%d][y%d]: %d\n", x, y, button);
	if (button == 4)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->zoom += 1;
		ft_newmap(param);
	}
	if (button == 5)
	{
		ft_cleanmap(param);
		((t_mlx*)param)->zoom -= 1;
		ft_newmap(param);
	}
	return (0);
}
