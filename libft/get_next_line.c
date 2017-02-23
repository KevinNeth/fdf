/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kneth <kneth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:51:42 by kneth             #+#    #+#             */
/*   Updated: 2017/02/02 16:00:57 by kneth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			this_is_the_end(int ret, t_list *k, char **line)
{
	char *tmp;

	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		tmp = k->content;
		if (tmp[0])
		{
			*line = ft_strdup(k->content);
			free(k->content);
			k->content = NULL;
			return (1);
		}
	}
	return (0);
}

static t_list		*ft_fd(t_list **lst, int fd)
{
	t_list *tmp;

	if ((tmp = *lst))
	{
		while (tmp != NULL)
		{
			if (tmp->content_size == (size_t)fd)
				return (tmp);
			tmp = tmp->next;
		}
		if (!(tmp = ft_memalloc(sizeof(t_list))))
			return (NULL);
		tmp->content_size = fd;
		ft_lstadd(lst, tmp);
	}
	else
	{
		if (!(*lst = ft_memalloc(sizeof(t_list))))
			return (NULL);
		(*lst)->content_size = fd;
		tmp = *lst;
	}
	return (tmp);
}

static int			ft_found(char *s, t_list *k, char **line)
{
	*s = '\0';
	*line = ft_strdup(k->content);
	k->content = ft_memmove(k->content, s + 1, ft_strlen(s + 1) + 1);
	return (1);
}

static t_list		*ft_nofound(int *ret, int fd, t_list *lst)
{
	char buff[BUFF_SIZE + 1];
	char *tmp;

	if ((*ret = read(fd, buff, BUFF_SIZE)) <= 0)
		return (NULL);
	buff[*ret] = '\0';
	tmp = lst->content;
	lst->content = ft_strjoin(tmp, buff);
	free(tmp);
	return (lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*l = NULL;
	t_list			*k;
	char			*s;
	int				ret;

	if (line == NULL)
		return (-1);
	k = ft_fd(&l, fd);
	ret = 1;
	if (!k->content)
		k->content = ft_strnew(0);
	while (ret >= 1)
	{
		s = ft_strchr(k->content, '\n');
		if (s)
			return (ft_found(s, k, line));
		else
			ft_nofound(&ret, fd, k);
	}
	if (ret == 0 || ret == -1)
		return (this_is_the_end(ret, k, line));
	return (-1);
}
