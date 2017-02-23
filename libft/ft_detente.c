/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detente.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:39:35 by kneth             #+#    #+#             */
/*   Updated: 2016/11/21 11:04:39 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_detente2(int *j, int *k)
{
	int m;
	int l;
	int n;

	*j = *j - 1;
	*k = *k + 2;
	m = 0;
	n = 0;
	while (m++ < *j)
		ft_putchar(' ');
	ft_putchar('(');
	while (n++ < *k)
		ft_putchar('_');
	ft_putchar(')');
	l = m;
	while (l > 0)
	{
		ft_putchar(' ');
		l--;
	}
	ft_putchar('\n');
	while (*j > 0)
		ft_detente2(j, k);
}

void		ft_detente(int n)
{
	int i;
	int j;
	int k;

	j = 0;
	i = n / 2;
	while (j < i)
	{
		ft_putchar(' ');
		j++;
	}
	if (j == i)
	{
		ft_putchar('/');
		ft_putchar(')');
	}
	k = j;
	while (k > 0)
	{
		ft_putchar(' ');
		k--;
	}
	ft_putchar('\n');
	ft_detente2(&j, &k);
}
