/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:40:31 by kneth             #+#    #+#             */
/*   Updated: 2017/02/22 16:06:30 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_printerror(int i)
{
	if (i == -1)
		printf("%s\n", "No map O_O");
	if (i == -2)
		printf("%s\n", "Map invalide ;(");
	if (i == -3)
		printf("%s\n", "Code couleur invalide ;O");
	if (i == -42)
		printf("%s\n", "Erreur Malloc ;X");
	exit (-1);
}

static void		ft_checkcolor(char *str, int *i)
{
	int	count;

	count = 0;
	if (str[*i] == '0')
		(*i)++;
	if (str[*i] == 'x')
		(*i)++;
	while (ft_isdigit(str[*i]) || (str[*i] > 64 && str[*i] < 71))
	{
		(*i)++;
		count++;
	}
	if (count != 6)
		ft_printerror(-3);
}

static void		ft_checkcol(int *save, int *nl, int *nc)
{
	if (!*save)
		*save = *nc;
	else
	{
		if (*save != *nc)
			ft_printerror(-2);
	}
	*nc = 0;
	(*nl)++;
}

void			ft_checkvalid(char *str, int *nc, int *nl)
{
	int		i;
	int		save;

	i = 0;
	save = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
			(*nc)++;
		while (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
			i++;
		if (str[i] == ',')
		{
			i++;
			ft_checkcolor(str, &i);
		}
		if (!ft_isdigit(str[i]) && (str[i] != ' ' && str[i] != '\t' &&
			str[i] != '\n'))
			ft_printerror(-2);
		if (str[i++] == '\n')
			ft_checkcol(&save, nl, nc);
	}
	*nc = save;
	printf("%s\n", "Map valide =D");//a virer
}
